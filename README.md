# PROJECT REMOTE

A standalone Nintendo 3DS built-in IR feasibility test. No Wi-Fi, internet, external transmitter, adapter, or accessory.

## Important compatibility finding

The documented 3DS IRU service is an IrDA-SIR data-transfer interface. The public libctru API exposes data transfers and bitrate selection, but does not document a raw consumer-remote carrier-frequency or arbitrary mark/space waveform generator. Standard Samsung TV and Roku IR compatibility is therefore **not established**. This project intentionally does not send fake TV commands or claim universal-remote functionality.

An archived 3DS IR proof-of-concept exists at https://github.com/RedTopper/3DS-Remote. Its limitations must be reviewed rather than assuming it controls TVs.

## Build

Install devkitPro with the 3DS development tools, then run `make`. GitHub Actions builds a `.3dsx` artifact. This starter has not been compiled or tested on physical hardware in this environment. A successful build would not prove consumer IR compatibility.

## References

- https://www.3dbrew.org/wiki/IR_Services
- https://github.com/devkitPro/libctru/blob/master/libctru/include/3ds/services/ir.h
- https://github.com/RedTopper/3DS-Remote
- https://github.com/devkitPro/3ds-examples
