/* Handy for debug, but you won't always get what you expect out. Most useful
   with records, string, ints, float, etc. */

[@bs.val]
external prettyStringify:
  ('a, [@bs.as {json|null|json}] _, [@bs.as {json|2|json}] _) => string =
  "JSON.stringify";

/* Use this to make pretty tailwind styles. Autocomplete in your editor will
   help a lot for knowing what you can pass in, or just ask in the Discord, and
   @jsjoeio can you you! */
let tailwind = TW.make;

let containerClass =
  tailwind([
    MaxWidth(MaxW6xl),
    Margin(MxAuto),
    Padding(Pt20),
    TextAlign(TextCenter),
  ]);

let headlineClass =
  tailwind([FontSize(Text6xl), FontWeight(FontLight), Margin(Mb4)]);

let buttonClass = tailwind([]);

type state = {
  work_minutes: int,
  break_seconds: int,
};

type action =
  | Set_work_minutes(int)
  | Set_break_seconds(int);

[@react.component]
let make = () => {
  let (state, dispatcher) =
    React.useReducer(
      (state, action) => {
        switch (action) {
        | Set_work_minutes(work_minutes) => {...state, work_minutes}
        | Set_break_seconds(break_seconds) => {...state, break_seconds}
        }
      },
      {
        work_minutes:
          Dom.Storage.(
            localStorage
            ->getItem("work_minutes", _)
            ->Belt.Option.map(int_of_string)
            ->Belt.Option.getWithDefault(0)
          ),
        break_seconds:
          Dom.Storage.(
            localStorage
            ->getItem("break_seconds", _)
            ->Belt.Option.map(int_of_string)
            ->Belt.Option.getWithDefault(0)
          ),
      },
    );

  React.(
    <div className=containerClass>
      <p className=headlineClass>
        {j|Stretch your arms, and let's get started|j}->string
      </p>
      <p> <button className=buttonClass> "Start"->string </button> </p>
      <p> "Length of work sessions (in minutes)"->string </p>
      <input
        type_="number"
        value={state.work_minutes->string_of_int}
        onChange={event =>
          dispatcher(
            Set_work_minutes(
              event->ReactEvent.Form.target##value->int_of_string,
            ),
          )
        }
      />
      <p> "Length of break (in seconds)"->string </p>
      <input
        type_="number"
        value={state.break_seconds->string_of_int}
        onChange={event => {
          dispatcher(
            Set_break_seconds(
              event->ReactEvent.Form.target##value->int_of_string,
            ),
          )
        }}
      />
      <p>
        <SaveButton
          break_seconds={state.break_seconds}
          work_minutes={state.work_minutes}
        />
      </p>
      <Timer
        break_seconds={state.break_seconds}
        work_minutes={state.work_minutes}
      />
    </div>
  );
};