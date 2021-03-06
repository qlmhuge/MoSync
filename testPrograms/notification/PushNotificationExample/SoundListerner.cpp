/*
Copyright (C) 2011 MoSync AB

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License,
version 2, as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA.
*/

/**
 * @file SoundListener.h
 * @author Bogdan Iusco
 * @date 10 Nov 2011
 *
 * @brief Plays a sound repeatedly.
 */

// Sound length in milliseconds.
#define SOUND_LENGTH 182000

#include "SoundListener.h"

#include <conprint.h>
#include <mastdlib.h>

#include "MAHeaders.h"

/**
 * Constructor.
 */
SoundListener::SoundListener()
{

}

/**
 * Destructor.
 */
SoundListener::~SoundListener()
{
    MAUtil::Environment::getEnvironment().removeTimer(this);
}

/**
 * Start playing sound.
 */
void SoundListener::start()
{
    maSoundPlay(RES_SOUND, 0, maGetDataSize(RES_SOUND));
    MAUtil::Environment::getEnvironment().addTimer(this, SOUND_LENGTH, 0);
}

/**
 * Timer callback method.
 */
void SoundListener::runTimerEvent()
{
    maSoundPlay(RES_SOUND, 0, maGetDataSize(RES_SOUND));
}
