S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131107.2323
Build-Date: 2013.11.07 23:23:19

Crash Information
Process Name: QRDemo
PID: 27274
Date: 2013-11-30 12:06:06(GMT+0400)
Executable File Path: /opt/apps/vd84JCg9vN/bin/QRDemo
This process is multi-thread process
pid=27274 tid=27274
Signal: 11
      (SIGSEGV)
      si_code: -6
      signal sent by tkill (sent by pid 27274, uid 5000)

Register Information
r0   = 0x00000010, r1   = 0xabf09f78
r2   = 0xabf09f78, r3   = 0x0016f76e
r4   = 0x00000010, r5   = 0xabf09f78
r6   = 0x001e69d8, r7   = 0x0020bd80
r8   = 0xabf59330, r9   = 0x000e4860
r10  = 0xb447c940, fp   = 0xbebc8d10
ip   = 0xb430d1c5, sp   = 0xbebc8cd8
lr   = 0xb26ac220, pc   = 0xb430d1cc
cpsr = 0x60000030

Memory Information
MemTotal:   797320 KB
MemFree:     12832 KB
Buffers:      5376 KB
Cached:     170072 KB
VmPeak:     265100 KB
VmSize:     229716 KB
VmLck:           0 KB
VmHWM:       40980 KB
VmRSS:       40980 KB
VmData:     113824 KB
VmStk:         136 KB
VmExe:          32 KB
VmLib:       79928 KB
VmPTE:         168 KB
VmSwap:          0 KB

Maps Information
00008000 00010000 r-xp /usr/bin/launchpad_preloading_preinitializing_daemon
00018000 000dc000 rw-p [heap]
000dc000 0030d000 rw-p [heap]
ac993000 ac9c6000 r-xp /usr/lib/gstreamer-0.10/libgstcoreelements.so
ac9cf000 aca05000 r-xp /usr/lib/gstreamer-0.10/libgstcamerasrc.so
ae35a000 ae35d000 r-xp /usr/lib/bufmgr/libtbm_exynos4412.so.0.0.0
afba5000 afbf0000 r-xp /usr/lib/libGLESv1_CM.so.1.1
afbf9000 afc21000 r-xp /usr/lib/evas/modules/engines/gl_x11/linux-gnueabi-armv7l-1.7.99/module.so
afd77000 afd83000 r-xp /usr/lib/libtzsvc.so.0.0.1
afd90000 afd92000 r-xp /usr/lib/libemail-network.so.1.1.0
afd9a000 afe44000 r-xp /usr/lib/libuw-imap-toolkit.so.0.0.0
afe52000 afe56000 r-xp /usr/lib/libss-client.so.1.0.0
afe5e000 afe63000 r-xp /usr/lib/libmmutil_jpeg.so.0.0.0
afe6c000 afe86000 r-xp /usr/lib/libnfc.so.1.0.0
afe8e000 afe9f000 r-xp /usr/lib/libnfc-common-lib.so.1.0.0
afea8000 afece000 r-xp /usr/lib/libbluetooth-api.so.1.0.0
afed7000 afefd000 r-xp /usr/lib/libzmq.so.3.0.0
aff07000 aff10000 r-xp /usr/lib/libpims-ipc.so.0.0.30
aff18000 aff1d000 r-xp /usr/lib/libmemenv.so.1.1.0
aff25000 aff63000 r-xp /usr/lib/libleveldb.so.1.1.0
aff6c000 aff74000 r-xp /usr/lib/libgstfft-0.10.so.0.25.0
aff7c000 affa6000 r-xp /usr/lib/libgstaudio-0.10.so.0.25.0
affaf000 affbe000 r-xp /usr/lib/libgstvideo-0.10.so.0.25.0
affc6000 affde000 r-xp /usr/lib/libgstpbutils-0.10.so.0.25.0
affe0000 b0005000 r-xp /usr/lib/libxslt.so.1.1.16
b000e000 b0012000 r-xp /usr/lib/libeukit.so.1.7.99
b001a000 b0022000 r-xp /usr/lib/libui-gadget-1.so.0.1.0
b002a000 b0033000 r-xp /usr/lib/libmsg_vobject.so
b003c000 b0046000 r-xp /usr/lib/libdrm-client.so.0.0.1
b004e000 b0067000 r-xp /usr/lib/libmsg_plugin_manager.so
b0070000 b00a9000 r-xp /usr/lib/libmsg_framework_handler.so
b00b2000 b00e6000 r-xp /usr/lib/libmsg_transaction_proxy.so
b00ef000 b012f000 r-xp /usr/lib/libmsg_utils.so
b0130000 b013f000 r-xp /usr/lib/libemail-common-use.so.1.1.0
b0148000 b01c3000 r-xp /usr/lib/libemail-core.so.1.1.0
b01d3000 b021c000 r-xp /usr/lib/libemail-storage.so.1.1.0
b0225000 b0232000 r-xp /usr/lib/libemail-ipc.so.1.1.0
b023a000 b0264000 r-xp /usr/lib/libSLP-location.so.0.0.0
b026d000 b0276000 r-xp /usr/lib/libdownload-provider-interface.so.1.1.6
b027e000 b0285000 r-xp /usr/lib/libmedia-utils.so.0.0.0
b028d000 b028f000 r-xp /usr/lib/libmedia-hash.so.1.0.0
b0297000 b02b0000 r-xp /usr/lib/libmedia-thumbnail.so.1.0.0
b02b8000 b02ba000 r-xp /usr/lib/libmedia-svc-hash.so.1.0.0
b02c2000 b02da000 r-xp /usr/lib/libmedia-service.so.1.0.0
b02e2000 b02f6000 r-xp /usr/lib/libnetwork.so.0.0.0
b02ff000 b030a000 r-xp /usr/lib/libstt.so
b0312000 b0318000 r-xp /usr/lib/libbadge.so.0.0.1
b0320000 b0326000 r-xp /usr/lib/libcapi-appfw-app-manager.so.0.1.0
b032e000 b0334000 r-xp /usr/lib/libshortcut.so.0.0.1
b033d000 b0340000 r-xp /usr/lib/libminicontrol-provider.so.0.0.1
b0348000 b0353000 r-xp /usr/lib/liblivebox-service.so.0.0.1
b035b000 b0370000 r-xp /usr/lib/liblivebox-viewer.so.0.0.1
b0378000 b037c000 r-xp /usr/lib/libcapi-appfw-package-manager.so.0.0.30
b0384000 b05a1000 r-xp /usr/lib/libface-engine-plugin.so
b05ff000 b0605000 r-xp /usr/lib/libcapi-network-nfc.so.0.0.11
b060e000 b0625000 r-xp /usr/lib/libcapi-network-bluetooth.so.0.1.40
b062d000 b0635000 r-xp /usr/lib/libcapi-network-wifi.so.0.1.2_24
b063d000 b0656000 r-xp /usr/lib/libaccounts-svc.so.0.2.66
b065e000 b06d0000 r-xp /usr/lib/libcontacts-service2.so.0.9.114.7
b06ef000 b0732000 r-xp /usr/lib/libcalendar-service2.so.0.1.44
b073c000 b0744000 r-xp /usr/lib/libcapi-web-favorites.so
b0745000 b1947000 r-xp /usr/lib/libewebkit2.so.0.11.113
b1a2c000 b1a34000 r-xp /usr/lib/libpush.so.0.2.12
b1a3c000 b1a57000 r-xp /usr/lib/libmsg_mapi.so.0.1.0
b1a60000 b1a78000 r-xp /usr/lib/libemail-api.so.1.1.0
b1a80000 b1a89000 r-xp /usr/lib/libcapi-system-sensor.so.0.1.17
b1a92000 b1a95000 r-xp /usr/lib/libcapi-telephony-sim.so.0.1.7
b1a9d000 b1aa0000 r-xp /usr/lib/libcapi-telephony-network-info.so.0.1.0
b1aa9000 b1ab4000 r-xp /usr/lib/libcapi-location-manager.so.0.1.11
b1abc000 b1ac0000 r-xp /usr/lib/libcapi-web-url-download.so.0.1.0
b1ac8000 b1ae9000 r-xp /usr/lib/libcapi-content-media-content.so.0.2.59
b1af1000 b1af3000 r-xp /usr/lib/libcamsrcjpegenc.so.0.0.0
b1afb000 b1b0f000 r-xp /usr/lib/libwifi-direct.so.0.0
b1b17000 b1b1f000 r-xp /usr/lib/libcapi-network-tethering.so.0.1.0
b1b20000 b1b29000 r-xp /usr/lib/libcapi-network-connection.so.0.1.3_18
b1b31000 b1b65000 r-xp /usr/lib/libopenal.so.1.13.0
b1b6e000 b1b71000 r-xp /usr/lib/libalut.so.0.1.0
b1b7b000 b1b80000 r-xp /usr/lib/osp/libosp-speech-stt.so.1.2.2.0
b1b88000 b1ba6000 r-xp /usr/lib/osp/libosp-shell-core.so.1.2.2.1
b1baf000 b1c20000 r-xp /usr/lib/osp/libosp-shell.so.1.2.2.1
b1c32000 b1c38000 r-xp /usr/lib/osp/libosp-speech-tts.so.1.2.2.0
b1c40000 b1c63000 r-xp /usr/lib/osp/libosp-face.so.1.2.2.0
b1c6d000 b1ccb000 r-xp /usr/lib/osp/libosp-nfc.so.1.2.2.0
b1cd7000 b1d32000 r-xp /usr/lib/osp/libosp-bluetooth.so.1.2.2.0
b1d3e000 b1db1000 r-xp /usr/lib/osp/libosp-wifi.so.1.2.2.0
b1dbd000 b1e7e000 r-xp /usr/lib/osp/libosp-social.so.1.2.2.0
b1e88000 b1efd000 r-xp /usr/lib/osp/libosp-web.so.1.2.2.0
b1f0b000 b1f58000 r-xp /usr/lib/osp/libosp-messaging.so.1.2.2.0
b1f62000 b1f7f000 r-xp /usr/lib/osp/libosp-uix.so.1.2.2.0
b1f89000 b1fa8000 r-xp /usr/lib/osp/libosp-telephony.so.1.2.2.0
b1fb1000 b1fca000 r-xp /usr/lib/osp/libosp-locations.so.1.2.2.3
b1fd3000 b2030000 r-xp /usr/lib/osp/libosp-content.so.1.2.2.0
b2039000 b204b000 r-xp /usr/lib/osp/libosp-ime.so.1.2.2.0
b2054000 b206e000 r-xp /usr/lib/osp/libosp-json.so.1.2.2.0
b2078000 b208a000 r-xp /usr/lib/libmmfile_utils.so.0.0.0
b2092000 b2097000 r-xp /usr/lib/libmmffile.so.0.0.0
b209f000 b2103000 r-xp /usr/lib/libmmfcamcorder.so.0.0.0
b2110000 b21d5000 r-xp /usr/lib/osp/libosp-net.so.1.2.2.0
b21e3000 b2406000 r-xp /usr/lib/osp/libarengine.so
b2482000 b2487000 r-xp /usr/lib/libcapi-media-metadata-extractor.so
b248f000 b2494000 r-xp /usr/lib/libcapi-media-recorder.so.0.1.3
b249c000 b24a7000 r-xp /usr/lib/libcapi-media-camera.so.0.1.4
b24af000 b24b2000 r-xp /usr/lib/libcapi-media-sound-manager.so.0.1.1
b24ba000 b24c8000 r-xp /usr/lib/libcapi-media-player.so.0.1.1
b24d0000 b24f1000 r-xp /usr/lib/libopencore-amrnb.so.0.0.2
b24fa000 b24fe000 r-xp /usr/lib/libogg.so.0.7.1
b2506000 b2528000 r-xp /usr/lib/libvorbis.so.0.4.3
b2530000 b2534000 r-xp /usr/lib/libcapi-media-audio-io.so.0.2.0
b253c000 b255a000 r-xp /usr/lib/osp/libosp-image.so.1.2.2.0
b2563000 b2581000 r-xp /usr/lib/osp/libosp-vision.so.1.2.2.0
b258a000 b2681000 r-xp /usr/lib/osp/libosp-media.so.1.2.2.0
b2693000 b269d000 r-xp /usr/lib/evas/modules/engines/software_generic/linux-gnueabi-armv7l-1.7.99/module.so
b26a5000 b26b4000 r-xp /opt/usr/apps/vd84JCg9vN/bin/QRDemo.exe
b26bd000 b272f000 r-xp /usr/lib/libosp-env-config.so.1.2.2.1
b2737000 b2771000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b277a000 b277e000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b2786000 b27b7000 r-xp /usr/lib/libpulse.so.0.12.4
b27bf000 b2822000 r-xp /usr/lib/libasound.so.2.0.0
b282c000 b282f000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b2837000 b283b000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b2844000 b2861000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b2869000 b2877000 r-xp /usr/lib/libmmfsound.so.0.1.0
b287f000 b291b000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b2927000 b2968000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b2971000 b297a000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b2982000 b298f000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b2998000 b299e000 r-xp /usr/lib/libUMP.so
b29a6000 b29a9000 r-xp /usr/lib/libmm_ta.so.0.0.0
b29b1000 b29c0000 r-xp /usr/lib/libICE.so.6.3.0
b29ca000 b29cf000 r-xp /usr/lib/libSM.so.6.0.1
b29d7000 b29d8000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b29e0000 b29e8000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b29f0000 b29f8000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b2a03000 b2a06000 r-xp /usr/lib/libmmfsession.so.0.0.0
b2a0e000 b2a52000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b2a5b000 b2a6e000 r-xp /usr/lib/libEGL_platform.so
b2a77000 b2b4e000 r-xp /usr/lib/libMali.so
b2b59000 b2b5f000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2b67000 b2b68000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2b71000 b2baf000 r-xp /usr/lib/libGLESv2.so.2.0
b2bb7000 b2c02000 r-xp /usr/lib/libtiff.so.5.1.0
b2c0d000 b2c36000 r-xp /usr/lib/libturbojpeg.so
b2c4f000 b2c55000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b2c5d000 b2c63000 r-xp /usr/lib/libgif.so.4.1.6
b2c6b000 b2c8d000 r-xp /usr/lib/libavutil.so.51.73.101
b2c9c000 b2cca000 r-xp /usr/lib/libswscale.so.2.1.101
b2cd3000 b2fca000 r-xp /usr/lib/libavcodec.so.54.59.100
b32f1000 b330a000 r-xp /usr/lib/libpng12.so.0.50.0
b3313000 b3319000 r-xp /usr/lib/libfeedback.so.0.1.4
b3321000 b332d000 r-xp /usr/lib/libtts.so
b3335000 b334c000 r-xp /usr/lib/libEGL.so.1.4
b3355000 b340c000 r-xp /usr/lib/libcairo.so.2.11200.12
b3416000 b3430000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b3439000 b3d37000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b3daa000 b3daf000 r-xp /usr/lib/libslp_devman_plugin.so
b3db8000 b3dbb000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b3dc3000 b3dc7000 r-xp /usr/lib/libsysman.so.0.2.0
b3dcf000 b3de0000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b3de9000 b3deb000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b3df3000 b3df5000 r-xp /usr/lib/libdeviced.so.0.1.0
b3dfd000 b3e13000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b3e1b000 b3e1d000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b3e25000 b3e28000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b3e30000 b3e33000 r-xp /usr/lib/libdevice-node.so.0.1
b3e3b000 b3e3f000 r-xp /usr/lib/libheynoti.so.0.0.2
b3e47000 b3e8c000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3e95000 b3eaa000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b3eb3000 b3eb7000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b3ebf000 b3ec4000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b3ecc000 b3ecd000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b3ed6000 b3ed9000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b3ee1000 b3ee4000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b3eed000 b3ef0000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b3ef8000 b3ef9000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b3f01000 b3f0f000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b3f18000 b3f3a000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b3f42000 b3f45000 r-xp /usr/lib/libuuid.so.1.3.0
b3f4e000 b3f6c000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b3f74000 b3f8b000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b3f94000 b3f95000 r-xp /usr/lib/libpmapi.so.1.2
b3f9d000 b3fa5000 r-xp /usr/lib/libminizip.so.1.0.0
b3fad000 b3fb8000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b3fc0000 b4098000 r-xp /usr/lib/libxml2.so.2.7.8
b40a5000 b40c3000 r-xp /usr/lib/libpcre.so.0.0.1
b40cb000 b40ce000 r-xp /usr/lib/libiniparser.so.0
b40d7000 b40db000 r-xp /usr/lib/libhaptic.so.0.1
b40e3000 b40ee000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b40fb000 b4100000 r-xp /usr/lib/libdevman.so.0.1
b4109000 b410d000 r-xp /usr/lib/libchromium.so.1.0
b4115000 b411b000 r-xp /usr/lib/libappsvc.so.0.1.0
b4123000 b4124000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b4134000 b4136000 r-xp /opt/usr/apps/vd84JCg9vN/bin/QRDemo
b413e000 b4144000 r-xp /usr/lib/libalarm.so.0.0.0
b414d000 b415f000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b4167000 b4467000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b4486000 b4490000 r-xp /lib/libnss_files-2.13.so
b4499000 b44a2000 r-xp /lib/libnss_nis-2.13.so
b44ab000 b44bc000 r-xp /lib/libnsl-2.13.so
b44c7000 b44cd000 r-xp /lib/libnss_compat-2.13.so
b44d6000 b44df000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b4807000 b4818000 r-xp /usr/lib/libcom-core.so.0.0.1
b4820000 b4822000 r-xp /usr/lib/libdri2.so.0.0.0
b482a000 b4832000 r-xp /usr/lib/libdrm.so.2.4.0
b483a000 b483e000 r-xp /usr/lib/libtbm.so.1.0.0
b4846000 b4849000 r-xp /usr/lib/libXv.so.1.0.0
b4851000 b491c000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b4932000 b4942000 r-xp /usr/lib/libnotification.so.0.1.0
b494a000 b496e000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b4977000 b4987000 r-xp /lib/libresolv-2.13.so
b498b000 b498d000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b4995000 b4ae8000 r-xp /usr/lib/libcrypto.so.1.0.0
b4b06000 b4b52000 r-xp /usr/lib/libssl.so.1.0.0
b4b5e000 b4b8a000 r-xp /usr/lib/libidn.so.11.5.44
b4b93000 b4b9d000 r-xp /usr/lib/libcares.so.2.0.0
b4ba5000 b4bbc000 r-xp /lib/libexpat.so.1.5.2
b4bc6000 b4bea000 r-xp /usr/lib/libicule.so.48.1
b4bf3000 b4bfb000 r-xp /usr/lib/libsf_common.so
b4c03000 b4c9e000 r-xp /usr/lib/libstdc++.so.6.0.14
b4cb1000 b4d8e000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b4d99000 b4dbe000 r-xp /usr/lib/libexif.so.12.3.3
b4dd2000 b4ddc000 r-xp /usr/lib/libethumb.so.1.7.99
b4de4000 b4e28000 r-xp /usr/lib/libsndfile.so.1.0.25
b4e36000 b4e38000 r-xp /usr/lib/libctxdata.so.0.0.0
b4e40000 b4e4e000 r-xp /usr/lib/libremix.so.0.0.0
b4e56000 b4e57000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b4e5f000 b4e78000 r-xp /usr/lib/liblua-5.1.so
b4e81000 b4e88000 r-xp /usr/lib/libembryo.so.1.7.99
b4e91000 b4e94000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b4e9c000 b4ed9000 r-xp /usr/lib/libcurl.so.4.3.0
b4ee3000 b4ee7000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b4ef0000 b4f5a000 r-xp /usr/lib/libpixman-1.so.0.28.2
b4f67000 b4f8b000 r-xp /usr/lib/libfontconfig.so.1.5.0
b4f94000 b4ff0000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b5002000 b5016000 r-xp /usr/lib/libfribidi.so.0.3.1
b501e000 b5073000 r-xp /usr/lib/libfreetype.so.6.8.1
b507e000 b50a2000 r-xp /usr/lib/libjpeg.so.8.0.2
b50ba000 b50d1000 r-xp /lib/libz.so.1.2.5
b50d9000 b50e6000 r-xp /usr/lib/libsensor.so.1.1.0
b50f1000 b50f3000 r-xp /usr/lib/libapp-checker.so.0.1.0
b50fb000 b5101000 r-xp /usr/lib/libxdgmime.so.1.1.0
b6218000 b6300000 r-xp /usr/lib/libicuuc.so.48.1
b630d000 b642d000 r-xp /usr/lib/libicui18n.so.48.1
b643b000 b643e000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b6446000 b644f000 r-xp /usr/lib/libvconf.so.0.2.45
b6457000 b6465000 r-xp /usr/lib/libail.so.0.1.0
b646d000 b6485000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b6486000 b648b000 r-xp /usr/lib/libffi.so.5.0.10
b6493000 b6494000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b649c000 b64a6000 r-xp /usr/lib/libXext.so.6.4.0
b64af000 b64b2000 r-xp /usr/lib/libXtst.so.6.1.0
b64ba000 b64c0000 r-xp /usr/lib/libXrender.so.1.3.0
b64c8000 b64ce000 r-xp /usr/lib/libXrandr.so.2.2.0
b64d6000 b64d7000 r-xp /usr/lib/libXinerama.so.1.0.0
b64e0000 b64e9000 r-xp /usr/lib/libXi.so.6.1.0
b64f1000 b64f4000 r-xp /usr/lib/libXfixes.so.3.1.0
b64fc000 b64fe000 r-xp /usr/lib/libXgesture.so.7.0.0
b6506000 b6508000 r-xp /usr/lib/libXcomposite.so.1.0.0
b6510000 b6511000 r-xp /usr/lib/libXdamage.so.1.1.0
b651a000 b6521000 r-xp /usr/lib/libXcursor.so.1.0.2
b6529000 b6531000 r-xp /usr/lib/libemotion.so.1.7.99
b6539000 b6554000 r-xp /usr/lib/libecore_con.so.1.7.99
b655d000 b6562000 r-xp /usr/lib/libecore_imf.so.1.7.99
b656b000 b6573000 r-xp /usr/lib/libethumb_client.so.1.7.99
b657b000 b657d000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b6585000 b6589000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b6592000 b65a8000 r-xp /usr/lib/libefreet.so.1.7.99
b65b2000 b65bb000 r-xp /usr/lib/libedbus.so.1.7.99
b65c3000 b65c8000 r-xp /usr/lib/libecore_fb.so.1.7.99
b65d1000 b662d000 r-xp /usr/lib/libedje.so.1.7.99
b6637000 b664e000 r-xp /usr/lib/libecore_input.so.1.7.99
b6669000 b666e000 r-xp /usr/lib/libecore_file.so.1.7.99
b6676000 b6693000 r-xp /usr/lib/libecore_evas.so.1.7.99
b669c000 b66db000 r-xp /usr/lib/libeina.so.1.7.99
b66e4000 b6793000 r-xp /usr/lib/libevas.so.1.7.99
b67b5000 b67c8000 r-xp /usr/lib/libeet.so.1.7.99
b67d1000 b683b000 r-xp /lib/libm-2.13.so
b6847000 b684e000 r-xp /usr/lib/libutilX.so.1.1.0
b6856000 b685b000 r-xp /usr/lib/libappcore-common.so.1.1
b6863000 b686e000 r-xp /usr/lib/libaul.so.0.1.0
b6877000 b68ab000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b68b4000 b68e4000 r-xp /usr/lib/libecore_x.so.1.7.99
b68ed000 b6902000 r-xp /usr/lib/libecore.so.1.7.99
b6919000 b6a39000 r-xp /usr/lib/libelementary.so.1.7.99
b6a4c000 b6a4f000 r-xp /lib/libattr.so.1.1.0
b6a57000 b6a59000 r-xp /usr/lib/libXau.so.6.0.0
b6a61000 b6a67000 r-xp /lib/librt-2.13.so
b6a70000 b6a78000 r-xp /lib/libcrypt-2.13.so
b6aa8000 b6aab000 r-xp /lib/libcap.so.2.21
b6ab3000 b6ab5000 r-xp /usr/lib/libiri.so
b6abd000 b6ad2000 r-xp /usr/lib/libxcb.so.1.1.0
b6ada000 b6ae5000 r-xp /lib/libunwind.so.8.0.1
b6b13000 b6c30000 r-xp /lib/libc-2.13.so
b6c3e000 b6c47000 r-xp /lib/libgcc_s-4.5.3.so.1
b6c4f000 b6c52000 r-xp /usr/lib/libsmack.so.1.0.0
b6c5a000 b6c86000 r-xp /usr/lib/libdbus-1.so.3.7.2
b6c8f000 b6c93000 r-xp /usr/lib/libbundle.so.0.1.22
b6c9b000 b6c9d000 r-xp /lib/libdl-2.13.so
b6ca6000 b6d80000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b6d89000 b6df3000 r-xp /usr/lib/libsqlite3.so.0.8.6
b6dfd000 b6e0a000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b6e13000 b6ef9000 r-xp /usr/lib/libX11.so.6.3.0
b6f04000 b6f18000 r-xp /lib/libpthread-2.13.so
b6f28000 b6f2c000 r-xp /usr/lib/libappcore-efl.so.1.1
b6f35000 b6f36000 r-xp /usr/lib/libdlog.so.0.0.0
b6f3e000 b6f42000 r-xp /usr/lib/libsys-assert.so
b6f4a000 b6f67000 r-xp /lib/ld-2.13.so
bebaa000 bebcb000 rwxp [stack]
End of Maps Information

Callstack Information (PID:27274)
Call Stack Count: 24
 0: Tizen::Io::RemoteMessagePort::SendMessage(Tizen::Base::Collection::IMap const*) + 0x7 (0xb430d1cc) [/usr/lib/osp/libosp-appfw.so] + 0x1a61cc
 1: QRMessagePort::SendMessage(Tizen::Base::Collection::IMap const*) + 0x8c (0xb26ac220) [/opt/apps/vd84JCg9vN/bin/QRDemo.exe] + 0x7220
 2: Tracker::OnCameraPreviewed(Tizen::Base::ByteBuffer&, unsigned long) + 0x710 (0xb26b1458) [/opt/apps/vd84JCg9vN/bin/QRDemo.exe] + 0xc458
End of Call Stack

Package Information
Package Name: vd84JCg9vN.QRDemo
Package ID : vd84JCg9vN
Version: 1.0.0
Package Type: tpk
App Name: QRDemo
App ID: vd84JCg9vN.QRDemo
Type: Application
Categories: (NULL)
