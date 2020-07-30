## time_window brief into
Here I have a code to produce AdcTDc time diff for Cerenkov and Calorimeter for both spectrometer.

Code will basically produce the plots for no hit selection and hit selections .

### code execution

To run code we need to load ROOT files by doing 

root -l /path/ to/ rootfile/filename.root.

and then do

T->Process("S(H)HMSGates.C").
