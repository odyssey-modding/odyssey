#!/usr/bin/env python3
import argparse
import subprocess
import json

# Output progress to the terminal
subprocess.run(["python3", "tools/common/progress.py"]);

# Generate the csv output that should be parsed into a json
progress_output = subprocess.check_output(["python3", "tools/common/progress.py", "--csv"])

# Parse the CSV output
csv_fields = progress_output.decode("utf-8").strip().split(",")

num_total = int(csv_fields[3])
matching_count = int(csv_fields[5])
non_matching_minor_count = int(csv_fields[7])
non_matching_major_count = int(csv_fields[9])

matching_percentage = (matching_count / num_total) * 100
non_matching_minor_percentage = (non_matching_minor_count / num_total) * 100
non_matching_major_percentage = (non_matching_major_count / num_total) * 100

progress_data = {
    "matching": {
        "label": "matching",
        "message": f"{matching_percentage:.5f}%",
    },
    "non_matching_minor": {
        "label": "non-matching (minor issues)",
        "message": f"{non_matching_minor_percentage:.5f}%",
    },
    "non_matching_major": {
        "label": "non-matching (major issues)",
        "message": f"{non_matching_major_percentage:.5f}%",
    }
}

shields_data = {
    "schemaVersion": 1,
    "label": "decompiled",
    "message": f"{matching_percentage:.3f}%",
    "color": "blue",
    "cacheSeconds": 3600,
    "style": "flat"
}

with open('data/progress.json', 'w') as json_file:
    json.dump(progress_data, json_file, indent=4)

with open('data/shields.json', 'w') as json_file:
    json.dump(shields_data, json_file, indent=4)

print("Progress data saved to 'data/progress.json'")
print("Shields data saved to 'data/shields.json'")
