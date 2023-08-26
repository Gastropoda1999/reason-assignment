module Styles = {
  open Css;

  let container =
    style([display(`flex), flexWrap(`wrap), justifyContent(`spaceAround)]);
};

[@react.component]
let make = () =>
  <div className=Styles.container>
  </div>;
