PACKAGES = "${PN}"
PACKAGE_ARCH = "${@bb.utils.contains("DEFAULTTUNE", "cortexa7hf", "cortexa7hf-vfp", "${DEFAULTTUNE}", d)}"

# To create a softcam:
# - install binary to /usr/bin/
# - install other stuff wherever you need it
# - fill in (mandatory)
#   CAMNAME: Name of softcam, preferably matches /usr/bin name
# - fill in (optional)
#   CAMSTART: Command to start the softcam, default to /usr/bin/${CAMNAME}
#   CAMSTOP: Command to stop the softcam, default to killall ${CAMNAME}
# Instead of CAMSTART/CAMSTOP, you can create an init.d script called init.${CAMNAME}

CAMLINK = "/etc/init.d/softcam"
CAMPATH = "/etc/init.d/softcam.${CAMNAME}"

CAMSTART ?= "exec start-stop-daemon -S -x /usr/bin/${CAMNAME}"
CAMSTOP  ?= "exec start-stop-daemon -K -R 2 -x /usr/bin/${CAMNAME}"

require ${SOFTCAM_INCLUDES}/softcam.inc
