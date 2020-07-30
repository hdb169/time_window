
import string

with open("SHMSADCGates.C", "r") as file:
    line = file.read()

# line = line.replace("HMS", "SHMS")
# line = line.replace("H_cal_1pr","P_precal")
# line = line.replace("*H","*P")
# line = line.replace("H_cer","P_ngcer")
# line = line.replace("H_gtr","P_gtr")
line=line.replace("[14]", "[256]")
line=line.replace("precal", "cal")
line=line.replace("Pos", "")
line=line.replace("posAdc","adc")

with open("SHMSADCGates.C", "w") as file:
    file.write(line)
