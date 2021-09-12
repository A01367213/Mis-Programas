import math

def cockroach_speed(s):
    s = s * 100000
    t = 3600
    r = s/t

    r = math.floor(r)
    return r
    
    # Good Luck!
    
speed = cockroach_speed(0.46222355040035323)
print(speed)
