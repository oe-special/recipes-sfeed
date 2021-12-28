EXTRA_OECMAKE += "\
	-DIPV6SUPPORT=0 \
	"

SUMMARY:${PN}:append = " (IPv4 only)"

DESCRIPTION:${PN} += "\n \
Note: You should never need this IPv4-ONLY version!"

RPROVIDES:${PN}  += "${CAMNAME}-ipv4"
RREPLACES:${PN}  += "${CAMNAME}"
RCONFLICTS:${PN} += "${CAMNAME}"
