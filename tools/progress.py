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

# Calculate percentages
num_total = int(csv_fields[3])
code_size_total = int(csv_fields[4])
matching_count = int(csv_fields[5])
equivalent_count = int(csv_fields[7])
non_matching_minor_count = int(csv_fields[9])

matching_percentage = (matching_count / num_total) * 100
equivalent_percentage = (equivalent_count / num_total) * 100
non_matching_minor_percentage = (non_matching_minor_count / num_total) * 100

# Create a dictionary with percentages
progress_data = {
    "version": int(csv_fields[0]),
    "timestamp": int(csv_fields[1]),
    "git_hash": csv_fields[2],
    "num_total": num_total,
    "code_size_total": code_size_total,
    "matching": {
        "count": matching_count,
        "percentage": matching_percentage,
        "code_size": int(csv_fields[6])
    },
    "equivalent": {
        "count": equivalent_count,
        "percentage": equivalent_percentage,
        "code_size": int(csv_fields[8])
    },
    "non_matching_minor": {
        "count": non_matching_minor_count,
        "percentage": non_matching_minor_percentage,
        "code_size": int(csv_fields[10])
    }
}

with open('data/progress.json', 'w') as json_file:
    json.dump(progress_data, json_file, indent=4)

print("Progress data saved to 'data/progress.json'")
