#!/usr/bin/env bash
ARG1=${1:-$(curl -s https://ipinfo.io/ip)}
curl -s ipinfo.io/"$ARG1" | grep -e "country" -e "loc" | xargs > "result.txt"
