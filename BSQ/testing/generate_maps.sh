#!/bin/bash

# Check if a folder argument was provided
if [ -z "$1" ]; then
    echo "Usage: $0 <output_folder>"
    exit 1
fi

OUTPUT_FOLDER="$1"

# Create the folder if it doesn't exist
mkdir -p "$OUTPUT_FOLDER"

for i in {1..10}; do
    X=$(( RANDOM % 20 + 5 ))  # Random number from 1 to 10
    Y=$(( RANDOM % 20 + 5 ))  # Random number from 1 to 10
    D=$(( RANDOM % 5 + 1 ))   # Random number from 1 to 3

    OUTPUT_FILE="${OUTPUT_FOLDER}/map_${X}_${Y}_${D}"
    
    perl map_generator.pl "$X" "$Y" "$D" > "$OUTPUT_FILE"
    echo "Generated: $OUTPUT_FILE"
done

