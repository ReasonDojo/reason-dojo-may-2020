/*
   Ideas for exploration: requestAnimationFrame
   Add routes for idle/working/on-break
   Clear/restore the interval when exiting/restarting
 */

type schedule = {
  starts: float,
  ends: float,
};

type state =
  | Idle
  | Working(schedule)
  | OnBreak(schedule);

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
      Working({starts: nowMs, ends: nowMs +. fiveMinutesInMilliseconds})
    );

  React.useEffect0(() => {
    let intervalHandle =
      Js.Global.setInterval(() => {setNowMs(_ => Js.Date.now())}, 16);
    Some(() => {Js.Global.clearInterval(intervalHandle)});
  });

  React.useEffect1(
    () => {
      switch (state) {
      | Idle => ()
      | Working({ends}) =>
        nowMs > ends
          ? setState(_ =>
              OnBreak({
                starts: nowMs,
                ends: nowMs +. fiveMinutesInMilliseconds,
              })
            )
          : ()
      | OnBreak({ends}) =>
        nowMs > ends
          ? setState(_ =>
              Working({
                starts: nowMs,
                ends: nowMs +. fiveMinutesInMilliseconds,
              })
            )
          : ()
      };
      None;
    },
    [|nowMs|],
  );

  let progress =
    switch (state) {
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
         {switch (state) {
         | Idle => {j|Click start when you start working|j}->string
         | Working(_) =>
           {j|Keep working!|j}->string;
         | OnBreak(_) =>
           {j|Stretch your arms.|j}->string;
         }}
      </p>
      progress
      <br />
      <span className=TW.([FontSize(TextLg)] |> make)>
        {switch (state) {
         | Idle => {j|No break scheduled|j}->string
         | Working({ends}) =>
           let secondsRemaining = int_of_float((ends -. nowMs) /. 1000.0);
           {j|Next break in $secondsRemaining seconds.|j}->string;
         | OnBreak({ends}) =>
           let secondsRemaining = int_of_float((ends -. nowMs) /. 1000.0);
           {j|On break for another $secondsRemaining seconds|j}->string;
         }}
      </span>
      <div className=TW.([Display(Flex), JustifyContent(JustifyCenter), Margin(Mt24)] |> make)>
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
              switch (oldState) {
              | Idle =>
                Working({starts: now, ends: now +. fiveMinutesInMilliseconds})
              | _ => Idle
              }
            );
          }}>
          (
            switch (state) {
            | Idle => "Start"
            | _ => "Stop"
            }
          )
          ->string
        </button>
      </div>
    </div>
  );
};