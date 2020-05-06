[@react.component]
let make = (~break_seconds: int, ~work_minutes) => {
  React.(
    <button
      onClick={_ => {
        Dom.Storage.(
          localStorage->setItem(
                          "break_seconds",
                          break_seconds->string_of_int,
                          _,
                        )
        );
        Dom.Storage.(
          localStorage->setItem(
                          "work_minutes",
                          work_minutes->string_of_int,
                          _,
                        )
        );
      }}>
       "Save"->string </button> /* ReactDOMRe.Something.div(~className="", ()*/
  );
};