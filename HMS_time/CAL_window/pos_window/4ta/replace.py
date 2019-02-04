
import string

with open("HMSADCGates.C", "r") as file:
    line = file.read()

# replace with 2ta, 3ta, 4ta, neg with pos 

line = line.replace("3ta", "4ta")
#line = line.replace("neg","pos")
#line = line.replace("Neg","Pos")
#line = line.replace("[2]", "[13]")
#line = line.replace("P_precal","H_cal_1pr")
#line = line.replace("P_hgcer", "H_cer")
#line = line.replace('*P','*H')
#line = line.replace("P_ngcer_good","P_precal_goodNeg")

with open("HMSADCGates.C", "w") as file:
    file.write(line)
