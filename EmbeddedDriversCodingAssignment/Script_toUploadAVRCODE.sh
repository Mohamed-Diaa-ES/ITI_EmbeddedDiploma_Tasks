#!/bin/bash

avrdude -c usbasp -p m32 -U flash:w:release/firmware.hex:i