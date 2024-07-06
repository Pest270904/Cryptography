import subprocess
import re
filenames = [ "2MB","10MB","50MB","250MB","500MB","1GB"]
modes = ["SHA224","SHA256","SHA384","SHA512","SHA3_224","SHA3_256","SHA3_512","SHAKE128","SHAKE256"]

def run_command(filename, mode):
    command = [
        f".\hash.exe",      
    ]
    command.append("1")
    command.append(mode)
    command.append(f"./{filename}.txt")
    command.append("digest")
    
    if(mode == "SHAKE128" or mode == "SHAKE256"):
        command.append("64")

    result = subprocess.run(command, capture_output=True, text=True)
    
    return result.stdout 

def extract_time(output):
    match = re.search(r"1000 times: ([\d.]+) ms", output)
    if match:
        return float(match.group(1))
    return None

for mode in modes:
    print(f"---------------------{mode}---------------------")
    for filename in filenames:
        # sign
        output = run_command(filename, mode)
        # print(output)
        time = extract_time(output)

        if time is not None and time is not None:
            print(f"{filename}\t {time:.4f} ")
        else:
            print(f"Error: Failed to extract time for {filename}")
                    
            

# sudo apt-get update
# sudo apt-get install build-essential git cmake libboost-all-dev