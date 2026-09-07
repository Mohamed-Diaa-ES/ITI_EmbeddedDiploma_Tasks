#!/bin/bash
read Commitmessage
git add .
git commit -m"$Commitmessage"

git push origin main 