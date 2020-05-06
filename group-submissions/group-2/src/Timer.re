type state = {
  totalSeconds: int,
  currentInterval: option(Js.Global.intervalId),
  working: bool,
  running: bool,
};

type action =
  | StopWorking
  | StartWorking
  | ClearCurrentInterval(Js.Global.intervalId)
  | SetCurrentInterval(option(Js.Global.intervalId))
  | DecreaseTime
  | StartStop
  | SetTime(int, int);

let minuteToSecond = minutes => minutes * 60;

let startHandler = (dispatcher, state) => {
  dispatcher(StartStop);
  switch (state.currentInterval) {
  | Some(id) =>
    dispatcher(ClearCurrentInterval(id))
  | None =>
    let id = Js.Global.setInterval(() => { dispatcher(DecreaseTime) }, 1000);
    dispatcher(SetCurrentInterval(Some(id)));
  };
};

let useTimer = (seconds : int) => {
    let (time_remaining, setTimeRemaining) =
        React.useState(() => seconds);

    Js.log2("VALUE: ", time_remaining);

    let (interval_id, setIntervalId) =
        React.useState(() => None);

    let toggleTimer () = {
        switch (interval_id) {
            | Some(interval_id) => 
                Js.Global.clearInterval(interval_id)
                setIntervalId(_current_interval_id => None);
            | None =>
                let id = Js.Global.setInterval(() => {
                        Js.log2("Setting time remaning in toggleTimer with time remaining: ", time_remaining);
                        setTimeRemaining(time_remaining => { time_remaining - 1 })
                    },
                    1000);
                setIntervalId(_current_interval_id => Some(id))
        };
    };

    let isRunning () = {
        switch (interval_id) {
            | Some(_interval_id) => true
            | None => false
        }
    };

    React.useEffect2(() => {
        Js.log("Seconds changed!");
        setTimeRemaining(_ => seconds);
        None
        },
        (seconds, ()));

    (time_remaining, toggleTimer, isRunning())
};

[@react.component]
let make = (~break_seconds, ~work_minutes) => {
    Js.log3("Timer rendered with: ", break_seconds, work_minutes);

//   let (state, dispatcher) =
//     React.useReducer(
//       (state, action) => {
//         switch (action) {
//         | StopWorking => {...state, working: false}
//         | StartWorking => {...state, working: true}
//         | DecreaseTime => {...state, totalSeconds: state.totalSeconds - 1}
//         | SetCurrentInterval(intervalId) => {
//             ...state,
//             currentInterval: intervalId,
//           }
//         | ClearCurrentInterval(intervalId) =>
//             Js.Global.clearInterval(intervalId);
//             {
//                 ...state,
//                 currentInterval: None,
//             }
//         | StartStop => {...state, running: !state.working}
//         | SetTime(minutes, seconds) => {
//             ...state,
//             totalSeconds: minutes->minuteToSecond + seconds,
//           }
//         }
//       },
//       {
//         working: true,
//         running: false,
//         totalSeconds: work_minutes->minuteToSecond + break_seconds,
//         currentInterval: None,
//       },
//     );

    let (time_remaining, toggleTimer, is_running) = useTimer(work_minutes->minuteToSecond + break_seconds)

//   React.useEffect2(
//     () => {
//       dispatcher(SetTime(work_minutes, break_seconds));
//       None;
//     },
//     (break_seconds, work_minutes),
//   );

    React.(
        <div>
            <div>
                {
                    is_running
                        ? <div> "Working"->string </div>
                        : <div> "Pause"->string </div>
                }            
                <div> {time_remaining->string_of_int->string} </div>
            </div>
            // startHandler(dispatcher, state)->ignore
            <button onClick={_e => ()->toggleTimer}>
                {
                    is_running
                        ? "Stop"->string
                        : "Start"->string
                }
            </button>
        </div>
    );
};