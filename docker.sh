#!/bin/bash

# Parse command-line options
while getopts ":r:" opt; do
  case $opt in
    r)
      action="$OPTARG"
      ;;
    \?)
      echo "Invalid option: -$OPTARG"
      exit 1
      ;;
  esac
done

# Perform action based on the value of -r flag
if [ "$action" == "build" ]; then
  echo "Building Docker image ..."
  docker build --platform linux/x86_64 -t msp430 .
elif [ "$action" == "run" ]; then
  echo "Spinning up Docker container..."
  docker run -it -v "$(pwd)":/msp430 --platform linux/x86_64 --rm msp430 /bin/bash
else
  echo "Invalid value for -r flag"
  exit 1
fi