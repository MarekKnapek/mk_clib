@echo off
m4 -I "%~dp1." -- "%~1" > "%~dpn1"
