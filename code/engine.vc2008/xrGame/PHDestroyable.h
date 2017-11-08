#pragma once
#include "../xrPhysics/hit.h"

class CPhysicsShellHolder;
class CSE_Abstract;
class CPHDestroyableNotificate;
class CPHDestroyableNotificator
{

public:
	virtual		void						NotificateDestroy			(CPHDestroyableNotificate *dn)=0;
};


class	CPHDestroyable :
public  CPHDestroyableNotificator

{
public:			
			xr_vector<shared_str>						m_destroyed_obj_visual_names																											;
private:
			xr_vector<CPHDestroyableNotificate *>		m_notificate_objects																													;
			u16											m_depended_objects																														;
			Flags8										m_flags																																	;
			SHit										m_fatal_hit																																;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			enum
			{
				fl_destroyable		= 1<<0,
				fl_destroyed		= 1<<1,
				fl_released			= 1<<2,
			};
	virtual CPhysicsShellHolder*		PPhysicsShellHolder			()																											=0;
public:
										CPHDestroyable				()																											;
			void						Init						()																											;
			void						RespawnInit					()																											;
			void						SetFatalHit					(const SHit& hit)																							;
			void						Destroy						(u16 ref_id=u16(-1),LPCSTR section="ph_skeleton_object")													;	
			SHit						&FatalHit					(){return m_fatal_hit;}
			void						Load						(LPCSTR section)																							;
			void						Load						(CInifile* ini,LPCSTR section)																				;
virtual		void						NotificateDestroy			(CPHDestroyableNotificate *dn)																				;
			void						PhysicallyRemoveSelf		()																											;
IC			bool						Destroyable					()										{return !!m_flags.test(fl_destroyable);}
IC			bool						Destroyed					()										{return !!m_flags.test(fl_destroyed);}
IC			bool						CanDestroy					()										{return m_flags.test(fl_destroyable)&&!m_flags.test(fl_destroyed)	;}
virtual		bool						CanRemoveObject				()																								{return true;}
virtual		void						SheduleUpdate				(u32 dt)																									;
virtual		void						GenSpawnReplace				(u16 source_id,LPCSTR section,shared_str visual_name)														;
virtual		void						InitServerObject			(CSE_Abstract*				D)																				;
private:
			void						NotificatePart				(CPHDestroyableNotificate *dn)																				;
			void						PhysicallyRemovePart		(CPHDestroyableNotificate *dn)																				;																											;
};