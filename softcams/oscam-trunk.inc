SUMMARY = "OScam ${PV} Open Source Softcam"

SRC_URI = "svn://www.streamboard.tv/svn/oscam;protocol=http;module=trunk;scmdata=keep"

EXTRA_OECMAKE += "\
	-DHAVE_PCSC=0 \
"

require oscam-common.inc

PV = "1.20+svn${SRCPV}"
S = "${WORKDIR}/trunk"

RPROVIDES_${PN} += "enigma2-plugin-softcams-oscam-atv"
RREPLACES_${PN} += "enigma2-plugin-softcams-oscam-atv"
RCONFLICTS_${PN} += "enigma2-plugin-softcams-oscam-atv"
