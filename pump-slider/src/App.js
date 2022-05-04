import Slider from './Slider';
import './App.css';

function App() {
  return (
    <div className="App">
     <Slider
        ariaLabelInput="Label for slider value"
        id="slider"
        labelText="Fan Speed"
        max={100}
        min={0}
        step={1}
        stepMuliplier={4}
        value={50}
      />
    </div>
  );
}

export default App;
