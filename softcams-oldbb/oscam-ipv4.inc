SUMMARY_${PN}_append = " (IPv4 only)"

DESCRIPTION_${PN} += "\n \
Note: You should never need this IPv4-ONLY version!"

RPROVIDES_${PN}  += "${CAMNAME}-ipv4"
RREPLACES_${PN}  += "${CAMNAME}"
RCONFLICTS_${PN} += "${CAMNAME}"
