/*
	This file defines network packet struture and design for data packet.
*/

#define FS_EXT3	0
#define FS_NTFS	1
#define SQL_PG	2
#define SQL_OR	3
#define SQL_MY	4

/*
	DESIGN: Data packet structure.
	
	A data packet will be generic structure, which embed protocol specific data packet.
	
	Broadly there will two catagories of Migration.
	1. Data Migration: From one format of data to another format.
		e.g. NTFS to EXT3. Postgres to MYSQL data.
	2. Code Migration: On basis of rules defined in <proto>.rule file, code from one
	format will be migrated to target rule based code.

	The Migration will be done by agents which will run on machine, where data is avilable,
	rather then transfering the data to server.
	Server will intiate the task, and will monitor the state and progress of task.
	

*/



typedef _data_packet
{
	_u8	agent_id;
	_u8	protocol_id;
	_u32	data_size;
	void	*data;
}data_packet;





