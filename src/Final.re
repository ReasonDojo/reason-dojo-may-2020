/*
   Ideas for exploration: requestAnimationFrame
   Add routes for idle/working/on-break
   Clear/restore the interval when exiting/restarting
 */

/* Handy for debug, but you won't always get what you expect out. Most useful
   with records, string, ints, float, etc. */
[@bs.val]
external prettyStringify:
  ('a, [@bs.as {json|null|json}] _, [@bs.as {json|2|json}] _) => string =
  "JSON.stringify";

type schedule = {
  starts: float,
  ends: float,
};

type activity =
  | Idle
  | Working(schedule)
  | OnBreak(schedule);

type state = {
  activity,
  workLengthMs: float,
  breakLengthMs: float,
};

let fiveMinutesInMilliseconds = 5.0 *. 1000.0;

let progressBar = (~starts, ~nowMs, ~ends) => {
  let totalLength = ends -. starts;
  let currentPosition = ends -. nowMs;

  let progress =
    Js.Math.floor((1.0 -. currentPosition /. totalLength) *. 100.0);

  <div
    style={ReactDOMRe.Style.make(
      ~width="100%",
      ~height="20px",
      ~backgroundColor="black",
      (),
    )}>
    <div
      style={ReactDOMRe.Style.make(
        ~width={j|$progress%|j},
        ~height="20px",
        ~backgroundColor="#fbf",
        (),
      )}
    />
  </div>;
};

[@react.component]
let make = () => {
  let (nowMs, setNowMs) = React.useState(() => Js.Date.now());

  let (state, setState) =
    React.useState(() =>
      {
        activity:
          Working({starts: nowMs, ends: nowMs +. fiveMinutesInMilliseconds}),
        workLengthMs: 20.0 *. 60.0 *. 1000.0,
        breakLengthMs: 5.0 *. 60.0 *. 1000.0,
      }
    );

  React.useEffect0(() => {
    let intervalHandle =
      Js.Global.setInterval(() => {setNowMs(_ => Js.Date.now())}, 16);
    Some(() => {Js.Global.clearInterval(intervalHandle)});
  });

  React.useEffect1(
    () => {
      switch (state.activity) {
      | Idle => ()
      | Working({ends}) =>
        nowMs > ends
          ? setState(oldState =>
              {
                ...oldState,
                activity:
                  OnBreak({
                    starts: nowMs,
                    ends: nowMs +. state.breakLengthMs,
                  }),
              }
            )
          : ()
      | OnBreak({ends}) =>
        nowMs > ends
          ? setState(oldState =>
              {
                ...oldState,
                activity:
                  Working({starts: nowMs, ends: nowMs +. state.workLengthMs}),
              }
            )
          : ()
      };
      None;
    },
    [|nowMs|],
  );

  let progress =
    switch (state.activity) {
    | Idle => progressBar(~starts=0.0, ~ends=1.0, ~nowMs=0.0)
    | Working({starts, ends})
    | OnBreak({starts, ends}) => progressBar(~starts, ~ends, ~nowMs)
    };

  React.(
    <div
      className=TW.(
        [
          MaxWidth(MaxW6xl),
          Margin(MxAuto),
          Padding(Pt20),
          TextAlign(TextCenter),
        ]
        |> make
      )>
      <p
        className=TW.(
          [FontSize(Text6xl), FontWeight(FontLight), Margin(Mb4)] |> make
        )>
        {switch (state.activity) {
         | Idle => {j|Click start when you start working|j}->string
         | Working(_) => {j|Keep working!|j}->string
         | OnBreak(_) => {j|Stretch your arms.|j}->string
         }}
      </p>
      progress
      <br />
      <span className=TW.([FontSize(TextLg)] |> make)>
        {switch (state.activity) {
         | Idle => {j|No break scheduled|j}->string
         | Working({ends}) =>
           let secondsRemaining = int_of_float((ends -. nowMs) /. 1000.0);
           {j|Next break in $secondsRemaining seconds.|j}->string;
         | OnBreak({ends}) =>
           let secondsRemaining = int_of_float((ends -. nowMs) /. 1000.0);
           {j|On break for another $secondsRemaining seconds|j}->string;
         }}
      </span>
      <div
        className=TW.(
          [Display(Flex), JustifyContent(JustifyCenter), Margin(Mt24)]
          |> make
        )>
        <button
          className=TW.(
            [
              BackgroundColor(BgOrange300),
              BackgroundColor(HoverBgOrange400),
              Display(Block),
              TextColor(TextBlack),
              FontWeight(FontBold),
              Padding(Py2),
              Padding(Px5),
              BorderRadius(Rounded),
            ]
            |> make
          )
          onClick={_ => {
            let now = Js.Date.now();
            setState(oldState =>
              {
                ...oldState,
                activity:
                  switch (oldState.activity) {
                  | Idle =>
                    Working({starts: now, ends: now +. state.workLengthMs})
                  | _ => Idle
                  },
              }
            );
          }}>
          (
            switch (state.activity) {
            | Idle => "Start"
            | _ => "Stop"
            }
          )
          ->string
        </button>
      </div>
      // Start of the Input
      <div
        className=TW.(
          [Margin(Mt24), Margin(MxAuto), MaxWidth(MaxWSm)] |> make
        )>
        {switch (state.activity) {
         | Idle =>
           <form
             className=TW.(
               [
                 BackgroundColor(BgWhite),
                 BoxShadow(ShadowMd),
                 BorderRadius(Rounded),
                 Padding(Px8),
                 Padding(Pb8),
                 Margin(Mb4),
                 Padding(Pt10),
                 Display(Flex),
                 FlexDirection(FlexCol),
                 AlignItems(ItemsCenter),
               ]
               |> make
             )>
             <div className=TW.([Margin(Mb4)] |> make)>
               <label
                 htmlFor="session-length"
                 className=TW.(
                   [
                     Display(Block),
                     TextColor(TextGray700),
                     FontSize(TextSm),
                     FontWeight(FontBold),
                     Margin(Mb2),
                   ]
                   |> make
                 )>
                 {React.string("Length of work sessions (mins)")}
               </label>
               <input
                 id="session-length"
                 type_="decimal"
                 placeholder="25"
                 onChange={event => {
                   switch (
                     float_of_string_opt(
                       ReactEvent.Form.target(event)##value,
                     )
                   ) {
                   | None => ()
                   | Some(minutes) =>
                     setState(oldState => {
                       let workLengthMs = minutes *. 60.0 *. 1000.0;
                       {
                         ...oldState,
                         workLengthMs,
                         activity:
                           switch (oldState.activity) {
                           | Working({starts}) =>
                             Working({starts, ends: starts +. workLengthMs})
                           | other => other
                           },
                       };
                     })
                   }
                 }}
                 className=TW.(
                   [
                     BoxShadow(Shadow),
                     MaxWidth(MaxWXs),
                     AppearanceNone,
                     BorderRadius(Rounded),
                     Padding(Py2),
                     Padding(Px3),
                     TextColor(TextGray700),
                     LineHeight(LeadingTight),
                     OutlineNone,
                   ]
                   |> make
                 )
               />
             </div>
             <div className=TW.([Margin(Mb4)] |> make)>
               <label
                 htmlFor="break-length"
                 className=TW.(
                   [
                     Display(Block),
                     TextColor(TextGray700),
                     FontSize(TextSm),
                     FontWeight(FontBold),
                     Margin(Mb2),
                   ]
                   |> make
                 )>
                 {React.string("Length of break (secs)")}
               </label>
               <input
                 id="break-length"
                 type_="decimal"
                 placeholder="20"
                 onChange={event => {
                   switch (
                     float_of_string_opt(
                       ReactEvent.Form.target(event)##value,
                     )
                   ) {
                   | None => ()
                   | Some(seconds) =>
                     setState(oldState => {
                       let breakLengthMs = seconds *. 1000.0;
                       {
                         ...oldState,
                         breakLengthMs,
                         activity:
                           switch (oldState.activity) {
                           | OnBreak({starts}) =>
                             OnBreak({starts, ends: starts +. breakLengthMs})
                           | other => other
                           },
                       };
                     })
                   }
                 }}
                 className=TW.(
                   [
                     BoxShadow(Shadow),
                     MaxWidth(MaxWXs),
                     AppearanceNone,
                     BorderRadius(Rounded),
                     Padding(Py2),
                     Padding(Px3),
                     TextColor(TextGray700),
                     LineHeight(LeadingTight),
                     OutlineNone,
                   ]
                   |> make
                 )
               />
             </div>
           </form>
         | Working(_) => React.null
         | OnBreak(_) => React.null
         }}
      </div>
    </div>
  );
};
