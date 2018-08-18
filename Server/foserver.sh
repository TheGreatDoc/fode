#! /bin/sh
### BEGIN INIT INFO
# Provides:          FOnlineServer
# Short-Description: FOnline server application
### END INIT INFO
#
# Author: jan0s1k <jan0s1k@fode.eu>
#
PATH=/usr/sbin:/usr/bin:/sbin:/bin
DESC="FOnline Server Daemon"
NAME=FOnlineServerDaemon
SCRIPTNAME=/etc/init.d/foserver
DAEMON_ARGS=
USER_PATH=/home/koniko/fode # Your FOServer localization
SERVER_PORT=2077 # From Port in FOnlineServer.cfg
IP_SERVER=127.0.0.1
ADMIN_PORT=4001 # From AdminPanelPort in FOnlineServer.cfg
ADMIN_PASS="1" # From Access_admin in FOnlineServer.cfg
DAEMON=$USER_PATH/$NAME
PIDFILE=$USER_PATH/foserver.pid # Not implemented
export LD_LIBRARY_PATH=/home/koniko/fode/libs:/lib:/usr/lib
. /lib/lsb/init-functions

case "$1" in
  start)
	log_daemon_msg "Starting $DESC" "$NAME"
	$DAEMON $DAEMON_ARGS
	log_end_msg $?
	;;
  stop)
	log_daemon_msg "Stopping $DESC" "$NAME"
	nc $IP_SERVER $ADMIN_PORT -c "sleep 2s && echo $ADMIN_PASS && sleep 2s && echo stop && sleep 2s && echo kill && echo exit"
	log_end_msg $?
	;;
  restart)
	log_daemon_msg "Restarting $DESC" "$NAME"
	nc $IP_SERVER $ADMIN_PORT -c "sleep 2s && echo $ADMIN_PASS && sleep 2s && echo stop && sleep 2s && echo kill && echo exit"
	$DAEMON
	log_end_msg $?
	;;
 force-restart)
	log_daemon_msg "Restarting with force $DESC" "$NAME"
	killall $NAME
	$DAEMON
	log_end_msg $?
	;;
  reloadcs)
	log_daemon_msg "Reloading Client Scripts"
	nc $IP_SERVER $ADMIN_PORT -c "sleep 2s && echo $ADMIN_PASS && sleep 2s && echo '~rcs' && sleep 2s && echo exit"
	log_end_msg $?
	;;
  reloads)
	log_daemon_msg "Reloading Scripts"
	nc $IP_SERVER $ADMIN_PORT -c "sleep 2s && echo $ADMIN_PASS && sleep 2s && echo '~reloadscripts' && echo exit"
	log_end_msg $?
	;;
  status)
	#sleep 2s && echo 'abc' && sleep 2s && echo 'state' | nc $IP_SERVER $ADMIN_PORT
	echo "Not implemented yet.."
	;;
  players)
	netstat -t -n|grep $SERVER_PORT|grep ESTABLISHED|wc -l
	;;
  *)
	echo "Usage: $SCRIPTNAME {start|stop|restart|force-restart|reloadcs|reloads|players}"
	exit 1
	;;
esac
exit 0
