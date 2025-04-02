with open("MessageLog.txt", "a") as file:
    message = str(123)
    file.write(message)
match pgn:
    case int(xF003):
        d1 = data[1]
        d2 = data[2]
        file.write("Accelerator pedal position :"+ d1 + "\n")
        file.write("Engine percent load at current speed: "+ d2 + "\n")
    case int(xF004):
        d1 = data[3]
        d2 = data[4]
        d = d1*(2**8)+ d2
        file.write("Engine speed is: "+ d +"\n")
    case int(xFD92):
        #might need different shifting to get data
        d1 = data[0]
        d1%(2**7)
        d1>>3
        file.write("Engine operating state: " + d1 + "\n")
    case int(xFEEE):
        d1 = data[0]
        file.write("Engine coolant temperature: " + d1 + "\n")
    case int(xFEEF):
        d1 = data[3]
        file.write("Engine oil pressure: " + d1 + "\n")
    case int(xFD07):
        #might need different shifting to get data
        d1 = data[1]
        d1%(2**3)
        d1>>1
        file.write("Engine oil pressure lamp command: " + d1 + "\n")
    case int(xFEBD):
        #might need different shifting to get data
        d1 = data[1]
        d1%(2**7)
        d1>>3
        file.write("Fan drive state: " + d1 + "\n")
    case int(xFEE3):
        d1 = data[19]*(2**8)+ data[20]
        file.write("Engine Reference Torque (Engine Configuration): " + d1 + "\n")
    case int(xFEF2):
        d1 = data[0]*(2**8)+ data[1]
        file.write("Engine Fuel Rate: " + d + "\n")
        d2 = data[6]
        file.write("Engine throttle valve 1 Possition: " + d2 + "\n")
        #2 parts
    case int(xFEF5):
        d1 = data[0]
        file.write("Barometric Pressure: " + d1 + "\n")
        d2= data[5]
        file.write("Engine Air Intake Temoerature: " + d2 + "\n")
    case int(xFEF7):
        d1 = data[4]*(2**8)+ data[5]
        file.write("Battery Potential / Power Input 1: " + d1 + "\n")
        d2 = data[6]*(2**8)+ data[7]
        file.write("Keyswitch Battery Potnetial: " + d2 + "\n")
    case int(xF01A):
        d1 = data[0]*(2**8)+ data[1]
        file.write("Engine Throttle Actuator 1 Control Command: " + d1 + "\n")
        d2 = data[4]*(2**8)+ data[5]
        file.write("Engine Fuel Actuator 1 Control Command: " + d2 + "\n")
        d3 = data[6]*(2**8)+ data[7]
        file.write("Engine Fuel Actuator 2 Control Command: " + d3 + "\n")
    case int(xFDD0):
        d1 = data[3]
        file.write("Engine Intake Manifold #2 Pressure: " + d1 + "\n")
    case int(xFEF6):
        d1 = data[1]
        file.write("Engine Intake Manifold #1 Pressure: " + d1 + "\n")
        d2 = data[2]
        file.write("Engine Intake Manifold 1 Temperature: " + d2 + "\n")
        d3 = data[3]
        file.write("Engine AIr Intake Pressure " + d3 + "\n")
    