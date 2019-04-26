EXTRA_OECMAKE += "\
	-DIPV6SUPPORT=1 \
	"

DESCRIPTION += "- IPv6 support\nThis version can connect to servers using IPv6 and/or IPv4."

RPROVIDES_${PN}  = "${CAMNAME}"
RREPLACES_${PN}  = "${CAMNAME}-ipv4"
RCONFLICTS_${PN} = "${CAMNAME}-ipv4"
