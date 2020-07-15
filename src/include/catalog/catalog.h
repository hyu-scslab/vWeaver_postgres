/*-------------------------------------------------------------------------
 *
 * catalog.h
 *	  prototypes for functions in backend/catalog/catalog.c
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/catalog.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef CATALOG_H
#define CATALOG_H

#include "catalog/pg_class.h"
#include "utils/relcache.h"
#ifdef VWEAVER
#ifdef VWEAVER_STAT
#include "datatype/timestamp.h"
#endif
#endif


extern bool IsSystemRelation(Relation relation);
extern bool IsToastRelation(Relation relation);
extern bool IsCatalogRelation(Relation relation);

extern bool IsSystemClass(Oid relid, Form_pg_class reltuple);
extern bool IsToastClass(Form_pg_class reltuple);

extern bool IsCatalogRelationOid(Oid relid);

extern bool IsCatalogNamespace(Oid namespaceId);
extern bool IsToastNamespace(Oid namespaceId);

extern bool IsReservedName(const char *name);

extern bool IsSharedRelation(Oid relationId);

extern Oid	GetNewOidWithIndex(Relation relation, Oid indexId,
							   AttrNumber oidcolumn);
extern Oid	GetNewRelFileNode(Oid reltablespace, Relation pg_class,
							  char relpersistence);
#ifdef VWEAVER
#ifdef VWEAVER_STAT

#define InvalidTimestamp	(-1)

typedef struct TimeSecData {
	Timestamp	sec;
	Timestamp	microsec;
} TimeSecData;
typedef TimeSecData* TimeSec;

typedef struct UpdateCostStatData {
	TimeSecData	begin_v_ridgy;
	TimeSecData	end_v_ridgy;
	TimeSecData	begin_k_ridgy;
	TimeSecData	end_k_ridgy;
	TimeSecData	begin_commit;
	TimeSecData	end_commit;
} UpdateCostStatData;
typedef UpdateCostStatData* UpdateCostStat;

extern UpdateCostStatData	update_cost_stat_data;
extern UpdateCostStat		update_cost_stat;

void CVCSetTimestampClear(TimeSec time);
void CVCGetTimestamp(TimeSec time);
#endif
#endif

#endif							/* CATALOG_H */
