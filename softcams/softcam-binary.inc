require ${SOFTCAM_INCLUDES}/softcam-binary.inc

LICENSE = "CLOSED"
require conf/license/license-close.inc

do_prepare_recipe_sysroot[noexec] = "1"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
deltask do_populate_sysroot
deltask do_package_qa
