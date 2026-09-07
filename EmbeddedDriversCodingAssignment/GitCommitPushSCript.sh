#!/bin/bash
git pull origin main
read Commitmessage
git add .
git commit -m"$Commitmessage"

git push origin main 