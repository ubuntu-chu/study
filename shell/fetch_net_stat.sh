#!/bin/sh

netstat -na|awk '/^tcp/{++S[$NF]}END{for(a in S)print a, S[a]}'
