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
    // bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded

  React.(
    <div >
      <button
className=TW.([BackgroundColor(BgBlue500), TextColor(TextWhite), FontWeight(FontBold), Padding(Py2), Padding(Px4), BorderRadius(Rounded)] |> make)
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
      progress
      <br />
      {switch (state) {
       | Idle => {j|No break scheduled|j}->string
       | Working({ends}) =>
         let secondsRemaining = int_of_float((ends -. nowMs) /. 1000.0);
         {j|Next break in $secondsRemaining seconds.|j}->string;
       | OnBreak({ends}) =>
         let secondsRemaining = int_of_float((ends -. nowMs) /. 1000.0);
         {j|On break for another $secondsRemaining seconds|j}->string;
       }}
    </div>
  );
};