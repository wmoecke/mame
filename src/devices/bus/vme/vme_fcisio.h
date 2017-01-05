// license:BSD-3-Clause
// copyright-holders:Joakim Larsson Edstrom
#ifndef VME_FCISIO_H
#define VME_FCISIO_H
#pragma once

#include "machine/scnxx562.h"
#include "machine/68230pit.h"
#include "bus/vme/vme.h"

extern const device_type VME_FCISIO1;

class vme_fcisio1_card_device : 
	public device_t
	,public device_vme_card_interface
{
public:
	vme_fcisio1_card_device(const machine_config &mconfig, device_type type, const char *name, const char *tag, device_t *owner, uint32_t clock, const char *shortname, const char *source);
	vme_fcisio1_card_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	// optional information overrides
	virtual machine_config_constructor device_mconfig_additions() const override;
	virtual const tiny_rom_entry *device_rom_region() const override;

	DECLARE_READ16_MEMBER (bootvect_r);
	DECLARE_READ8_MEMBER (config_rd);

	/* Dummy driver routines */
	DECLARE_READ8_MEMBER (not_implemented_r);
	DECLARE_WRITE8_MEMBER (not_implemented_w);

protected:
	virtual void device_start() override;
	virtual void device_reset() override;

private:
	required_device<cpu_device> m_maincpu;
	required_device<duscc68562_device> m_duscc0;
	required_device<duscc68562_device> m_duscc1;
	required_device<duscc68562_device> m_duscc2;
	required_device<duscc68562_device> m_duscc3;

	required_device<pit68230_device> m_pit;

	// Pointer to System ROMs needed by bootvect_r
	uint16_t  *m_sysrom;
};

#endif // VME_FCISIO_H