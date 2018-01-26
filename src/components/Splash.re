open BsReactNative;

type state = {
  offset: Animated.Value.t
};

type action = Noop;

let component = ReasonReact.reducerComponent("SplashRe");

let logoSize = 60.0;
let mid_h = Dimensions.get(`window)##height |> float_of_int |> (x => x /. 2.0);
let logoPosY = mid_h -. (logoSize /. 2.);

let logoStyle = (offset) => Style.(style([
  fontSize(Float(logoSize)),
  position(Absolute),
  top( Animated(offset) ) /* <--------------- THE CULPRIT (runtime error) --------------- */
]));

let wrapperStyle = Style.(style([
  flex(1.),
  justifyContent(Center),
  alignItems(Center),
]));

let make = (_children) => {
  ...component,

  initialState: () => {
    offset: Animated.Value.create(logoPosY)
  },

  didMount: self => {
    Animated.CompositeAnimation.start(
      Animated.Timing.animate(
        ~value=self.state.offset,
        ~toValue=`raw( logoPosY -. 120. ),
        ~delay=1000.,
        ~duration=3400.,
        ()
      ),
      ()
    );
    ReasonReact.NoUpdate
  },

  /* Can't make a stateful component without reducer, so just noop here */
  reducer: (action, _state) => switch (action) {
    | Noop => ReasonReact.NoUpdate
  },

  render: ({state}) => {
    <View style=wrapperStyle>
      <Text value="The Logo" style=logoStyle(state.offset) />
    </View>
  }
};
