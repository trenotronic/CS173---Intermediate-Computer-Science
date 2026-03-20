#=======================================
# Tren Meckel, Jiamin Liu
# Project 1
# CS 173
# January 2024
#=======================================


def freeDrKretchmar(t1_on, t1_off, t2_on, t2_off, t_escape):
    """Print if DrKretchmar escapes, if he does escape, print the time of his escape."""
    for time in range(1440):   # Loop through 1440 minutes (24 hours) because when done is the time it goes back to midnight again
        if 0 <= time % (t1_on + t1_off) < t1_on or 0 <= time % (t2_on + t2_off) < t2_on: # Check if either light is on at the   current time
            if time >= t_escape:    # Check if the escape time has been reached
                print("CAUGHT")
                break
        else:
            if time >= t_escape:    # Check if the escape time has been reached
                print("ESCAPE")
                print("Time of escape:", time, "minutes")
                break
                
        
def main():
    # Get user inputs for timing parameters
    t1_on = float(input("Enter the length of time the first security light stays on: "))
    t1_off = float(input("Enter the length of time the first security light stays off: "))
    t2_on = float(input("Enter the length of time the second security light stays on: "))
    t2_off = float(input("Enter the length of time the second security light stays off: "))
    t_escape = float(input("Enter the time in minutes after midnight when Dr. K dashes: "))

    # Call on the function with provided inputs
    freeDrKretchmar(t1_on, t1_off, t2_on, t2_off, t_escape)

main()