The following command starts mongod as a daemon and records log output to /var/log/mongodb.log.

mongod --fork --logpath /var/log/mongodb.log







Stop mongod Processes

In a clean shutdown a mongod completes all pending operations, flushes all data to data files, and closes all data files. Other shutdowns are unclean and can compromise the validity of the data files.

To ensure a clean shutdown, always shutdown mongod instances using one of the following methods:

Use shutdownServer()
Shut down the mongod from the mongo shell using the db.shutdownServer() method as follows:

use admin
db.shutdownServer()





Use --shutdown
From the Linux command line, shut down the mongod using the --shutdown option in the following command:

mongod --shutdown

