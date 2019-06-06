EXTRA_OECMAKE += "\
	-DIPV6SUPPORT=0 \
	"

DESCRIPTION += "Note: You should never need this IPv4-ONLY version!"

RPROVIDES_${PN}  += "${CAMNAME}-ipv4"
RREPLACES_${PN}  += "${CAMNAME}"
RCONFLICTS_${PN} += "${CAMNAME}"
