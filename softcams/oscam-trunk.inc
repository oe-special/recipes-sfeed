SUMMARY = "OScam ${PV} Open Source Softcam"

SRC_URI="git://github.com/oscam-emu/oscam-patched.git;protocol=git"

CAMNAME = "oscam-trunk"

SRC_URI = "svn://www.streamboard.tv/svn/oscam;protocol=http;module=trunk;scmdata=keep"

EXTRA_OECMAKE += "\
	-DHAVE_PCSC=0 \
"

require oscam-common.inc

PV = "1.20+svn${SRCPV}"
SRCREV = "${AUTOREV}"
PR = "r0"

S = "${WORKDIR}/trunk"
