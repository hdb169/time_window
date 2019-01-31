
import string

with open("HMSADCGates.C", "r") as file:
    line = file.read()

line = line.replace("[4]", "[2]")
line = line.replace("P_hgcer_adc","H_cer_adc")
line = line.replace("P_hgcer", "H_cer")
line = line.replace('*P','*H')
#line = line.replace("P_ngcer_good","P_precal_goodNeg")

with open("HMSADCGates.C", "w") as file:
    file.write(line)
