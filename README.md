## React Native Animate.Value.t Bug

This project has been stripped down to a single component to isolate the issue.

## The Problem

I'm attempting to animate a css `top` value. In my code I have the following:

    top( Animated(offset) )

However, this causes a very strange runtime error:

    TypeError: Attempted to assign to readonly property.
    ...
    node_modules/react-native/Libraries/Animated/src/nodes/AnimatedValue.js:279:9 in stopTracking
    ...

That line is definitely causing it; if you replace it with `top( Pt(200.0) )` instead, then everything is ok (but no animation, obviously).

## Running The Code

This is an expo project. To get this going:

```bash
$ yarn
$ yarn start
```


This project was bootstrapped with [Create React Native App](https://github.com/react-community/create-react-native-app) and[Reason React Native Scripts](https://github.com/react-community/reason-react-native-scripts).

Below you'll find information about performing common tasks. The most recent version of this guide is available [here](https://github.com/react-community/create-react-native-app/blob/master/react-native-scripts/template/README.md).
