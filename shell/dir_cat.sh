#!/bin/bash

SERVICEDIR=/home/barnard/test

cd ${SERVICEDIR}
for SERVICE in * ; do
case "${SERVICE}" in
*)
echo "$SERVICE"
;;
esac
done



