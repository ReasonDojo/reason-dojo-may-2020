/* Handy for debug, but you won't always get what you expect out. Most useful
   with records, string, ints, float, etc. */
[@bs.val]
external prettyStringify:
  ('a, [@bs.as {json|null|json}] _, [@bs.as {json|2|json}] _) => string =
  "JSON.stringify";

/* You can use it like:
        let person = {name: "Joe"}
      <pre>
        <code>
          {prettyStringify(person)} // Returns the result of JSON.stringify(person, null, 2)
        </code>
      </pre>
   */

/* An example of making a new type */
type person = {name: string};
let joe = {name: "Joe"};

/* Use this to make pretty tailwind styles. Autocomplete in your editor will
   help a lot for knowing what you can pass in, or just ask in the Discord, and
   @jsjoeio can you you! */
let tailwind = TW.make;

/*
   You can get the current time as milliseconds (actually a float, not an integer) with:
   let now = Js.Date.now()
 */

/* Quick note about arithmetic on float:
       Normally to add, subtract, multiple, divide we do e.g. 1 + 1, 1 - 1, 1 * 1, 1 / 1

       That works perfectly fine for `int`s (integers)! But you need to use +., -., *., and /. for floats:
       1.0 -. 2.0 = -1.0
       1.0 +. 2.0 = 3.0
       1.0 *. 2.0 = 2.0
       1.0 /. 2.0 = 0.5

     You can get an int from a float with: int_of_float(1.0) => 1
     And you can get a float from an int with: float_of_int(1) => 1.0

     So this will work if you need it:
     float_of_int(10) +. 2.0 = 12.0

     We know, it's a bit of a bummer to have to tell the difference between adding
     ints and adding floats, but it has its advantages too!
     type activity =
     | OnBreak
     | Working;
   */

type activity =
  | OnBreak
  | Working
  | Idle;

type state = {
  nowMs: float,
  activity,
  endsAtMs: float,
  startsAtMs: float,
  timeIsOver: bool,
};

let stringOfActivity = activity => {
  switch (activity) {
  | OnBreak => "OnBreak"
  | Working => "Working"
  | Idle => "Idle"
  };
};

let fiveSecondsMs = 5.0 *. 1000.0;

[@react.component]
let make = () => {
  let (state, setState) =
    React.useState(() => {
      let nowMs = Js.Date.now();
      {
        activity: OnBreak,
        nowMs,
        endsAtMs: nowMs +. fiveSecondsMs,
        startsAtMs: nowMs,
        timeIsOver: false,
      };
    });

  let totalTimeMs = state.endsAtMs -. state.startsAtMs;
  let timeLeftMs = state.endsAtMs -. state.nowMs;
  let progress = timeLeftMs /. totalTimeMs *. 100.0;
  let progressString = Js.Float.toString(progress) ++ "%";

  React.useEffect1(
    () => {
      switch (state.timeIsOver) {
      | false => ()
      | true =>
        setState(oldState => {
          let activity =
            switch (oldState.activity) {
            | Idle => OnBreak
            | OnBreak => Working
            | Working => Idle
            };

          let nowMs = Js.Date.now();

          let timeIsOver = false;
          let startsAtMs = nowMs;
          let endsAtMs = startsAtMs +. fiveSecondsMs;

          let newState = {
            ...oldState,
            activity,
            timeIsOver,
            startsAtMs,
            endsAtMs,
          };
          newState;
        })
      };

      None;
    },
    [|state|],
  );

  React.useEffect(() => {
    let intervalHandle =
      Js.Global.setInterval(
        () => {
          setState(oldState => {
            let nowMs = Js.Date.now();
            let timeLeftMs = oldState.endsAtMs -. nowMs;
            let timeIsOver = timeLeftMs < 0.0;
            Js.log3("Time: ", nowMs, timeIsOver);

            {...oldState, nowMs, timeIsOver};
          })
        },
        1000,
      );
    Some(() => Js.Global.clearInterval(intervalHandle));
  });

  React.(
    <div
      className={tailwind([
        MaxWidth(MaxW6xl),
        Margin(MxAuto),
        Padding(Pt20),
        TextAlign(TextCenter),
      ])}>
      <p
        className={tailwind([
          FontSize(Text6xl),
          FontWeight(FontLight),
          Margin(Mb4),
        ])}>
        {j|Stretch your arms, and let's get started, Yeahy!|j}->string
      </p>
      <div> {React.string(stringOfActivity(state.activity))} </div>
      <input type_="decimal" />
      <div> {React.string(Js.Float.toString(timeLeftMs /. 1000.0))} </div>
      <div>
        {state.timeIsOver
           ? React.string("We are passed the time")
           : React.string("We are on time")}
      </div>
      <button
        onClick={_ =>
          setState(oldState => {
            let activity =
              switch (oldState.activity) {
              | Idle => OnBreak
              | OnBreak => Working
              | Working => Idle
              };

            let newState = {...oldState, activity};
            newState;
          })
        }>
        {React.string("Click me: ")}
      </button>
      <div
        style={ReactDOMRe.Style.make(
          ~height="20px",
          ~width="100%",
          ~backgroundColor="white",
          (),
        )}>
        <div
          style={ReactDOMRe.Style.make(
            ~height="20px",
            ~width=progressString,
            ~backgroundColor="pink",
            (),
          )}
        />
      </div>
    </div>
  );
};