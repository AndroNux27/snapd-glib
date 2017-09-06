/*
 * Copyright (C) 2017 Canonical Ltd.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#include "config.h"

#include "snapd-channel.h"
#include "snapd-enum-types.h"

/**
 * SECTION:snapd-channel
 * @short_description: Snap channel metadata
 * @include: snapd-glib/snapd-glib.h
 *
 * A #SnapdChannel contains the metadata for a given snap chanel as returned
 * using snapd_snap_get_channels().
 */

/**
 * SnapdChannel:
 *
 * #SnapdChannel is an opaque data structure and can only be accessed
 * using the provided functions.
 *
 * Since: 1.20
 */

struct _SnapdChannel
{
    GObject parent_instance;

    gchar *channel;
    SnapdConfinement confinement;
    gchar *epoch;
    gchar *name;
    gchar *revision;
    gint64 size;
    gchar *version;
};

enum
{
    PROP_CHANNEL = 1,
    PROP_CONFINEMENT,
    PROP_EPOCH,
    PROP_NAME,
    PROP_REVISION,
    PROP_SIZE,
    PROP_VERSION,
    PROP_LAST
};

G_DEFINE_TYPE (SnapdChannel, snapd_channel, G_TYPE_OBJECT)

/**
 * snapd_channel_get_channel:
 * @channel: a #SnapdChannel.
 *
 * Get the channel this snap is from, e.g. "stable".
 *
 * Returns: a channel name.
 *
 * Since: 1.20
 */
const gchar *
snapd_channel_get_channel (SnapdChannel *channel)
{
    g_return_val_if_fail (SNAPD_IS_CHANNEL (channel), NULL);
    return channel->channel;
}

/**
 * snapd_channel_get_confinement:
 * @channel: a #SnapdChannel.
 *
 * Get the confinement this snap is using, e.g. %SNAPD_CONFINEMENT_STRICT.
 *
 * Returns: a #SnapdConfinement.
 *
 * Since: 1.20
 */
SnapdConfinement
snapd_channel_get_confinement (SnapdChannel *channel)
{
    g_return_val_if_fail (SNAPD_IS_CHANNEL (channel), SNAPD_CONFINEMENT_UNKNOWN);
    return channel->confinement;
}

/**
 * snapd_channel_get_epoch:
 * @channel: a #SnapdChannel.
 *
 * Get the epoch used on this channel, e.g. "1".
 *
 * Returns: an apoch.
 *
 * Since: 1.20
 */
const gchar *
snapd_channel_get_epoch (SnapdChannel *channel)
{
    g_return_val_if_fail (SNAPD_IS_CHANNEL (channel), NULL);
    return channel->epoch;
}

/**
 * snapd_channel_get_name:
 * @channel: a #SnapdChannel.
 *
 * Get the name of this channel. This is used to reference this channel, e.g. for
 * installing / removing.
 *
 * Returns: a name.
 *
 * Since: 1.20
 */
const gchar *
snapd_channel_get_name (SnapdChannel *channel)
{
    g_return_val_if_fail (SNAPD_IS_CHANNEL (channel), NULL);
    return channel->name;
}

/**
 * snapd_channel_get_revision:
 * @channel: a #SnapdChannel.
 *
 * Get the revision for this snap. The format of the string is undefined.
 * See also snapd_channel_get_version().
 *
 * Returns: a revision string.
 *
 * Since: 1.20
 */
const gchar *
snapd_channel_get_revision (SnapdChannel *channel)
{
    g_return_val_if_fail (SNAPD_IS_CHANNEL (channel), NULL);
    return channel->revision;
}

/**
 * snapd_channel_get_size:
 * @channel: a #SnapdChannel.
 *
 * Get the download size of this snap.
 *
 * Returns: a byte count.
 *
 * Since: 1.20
 */
gint64
snapd_channel_get_size (SnapdChannel *channel)
{
    g_return_val_if_fail (SNAPD_IS_CHANNEL (channel), 0);
    return channel->size;
}

/**
 * snapd_channel_get_version:
 * @channel: a #SnapdChannel.
 *
 * Get the version for this snap. The format of the string is undefined.
 * See also snapd_channel_get_revision().
 *
 * Returns: a version string.
 *
 * Since: 1.20
 */
const gchar *
snapd_channel_get_version (SnapdChannel *channel)
{
    g_return_val_if_fail (SNAPD_IS_CHANNEL (channel), NULL);
    return channel->version;
}

static void
snapd_channel_set_property (GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec)
{
    SnapdChannel *channel = SNAPD_CHANNEL (object);

    switch (prop_id) {
    case PROP_CHANNEL:
        g_free (channel->channel);
        channel->channel = g_strdup (g_value_get_string (value));
        break;
    case PROP_CONFINEMENT:
        channel->confinement = g_value_get_enum (value);
        break;
    case PROP_EPOCH:
        g_free (channel->epoch);
        channel->epoch = g_strdup (g_value_get_string (value));
        break;
    case PROP_NAME:
        g_free (channel->name);
        channel->name = g_strdup (g_value_get_string (value));
        break;
    case PROP_REVISION:
        g_free (channel->revision);
        channel->revision = g_strdup (g_value_get_string (value));
        break;
    case PROP_SIZE:
        channel->size = g_value_get_int64 (value);
        break;
    case PROP_VERSION:
        g_free (channel->version);
        channel->version = g_strdup (g_value_get_string (value));
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
        break;
    }
}

static void
snapd_channel_get_property (GObject *object, guint prop_id, GValue *value, GParamSpec *pspec)
{
    SnapdChannel *channel = SNAPD_CHANNEL (object);

    switch (prop_id) {
    case PROP_CHANNEL:
        g_value_set_string (value, channel->channel);
        break;
    case PROP_CONFINEMENT:
        g_value_set_enum (value, channel->confinement);
        break;
    case PROP_EPOCH:
        g_value_set_string (value, channel->epoch);
        break;
    case PROP_NAME:
        g_value_set_string (value, channel->name);
        break;
    case PROP_REVISION:
        g_value_set_string (value, channel->revision);
        break;
    case PROP_SIZE:
        g_value_set_int64 (value, channel->size);
        break;
    case PROP_VERSION:
        g_value_set_string (value, channel->version);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
        break;
    }
}

static void
snapd_channel_finalize (GObject *object)
{
    SnapdChannel *channel = SNAPD_CHANNEL (object);

    g_clear_pointer (&channel->channel, g_free);
    g_clear_pointer (&channel->epoch, g_free);
    g_clear_pointer (&channel->name, g_free);
    g_clear_pointer (&channel->revision, g_free);
    g_clear_pointer (&channel->version, g_free);
}

static void
snapd_channel_class_init (SnapdChannelClass *klass)
{
    GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

    gobject_class->set_property = snapd_channel_set_property;
    gobject_class->get_property = snapd_channel_get_property;
    gobject_class->finalize = snapd_channel_finalize;

    g_object_class_install_property (gobject_class,
                                     PROP_CHANNEL,
                                     g_param_spec_string ("channel",
                                                          "channel",
                                                          "Channel the snap is from",
                                                          NULL,
                                                          G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
    g_object_class_install_property (gobject_class,
                                     PROP_CONFINEMENT,
                                     g_param_spec_enum ("confinement",
                                                        "confinement",
                                                        "Confinement requested by the snap",
                                                        SNAPD_TYPE_CONFINEMENT, SNAPD_CONFINEMENT_UNKNOWN,
                                                        G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
    g_object_class_install_property (gobject_class,
                                     PROP_EPOCH,
                                     g_param_spec_string ("epoch",
                                                          "epoch",
                                                          "Epoch of this snap",
                                                          NULL,
                                                          G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
    g_object_class_install_property (gobject_class,
                                     PROP_NAME,
                                     g_param_spec_string ("name",
                                                          "name",
                                                          "The channel name",
                                                          NULL,
                                                          G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
    g_object_class_install_property (gobject_class,
                                     PROP_REVISION,
                                     g_param_spec_string ("revision",
                                                          "revision",
                                                          "Revision of this snap",
                                                          NULL,
                                                          G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
    g_object_class_install_property (gobject_class,
                                     PROP_SIZE,
                                     g_param_spec_int64 ("size",
                                                         "size",
                                                         "Download size in bytes",
                                                         G_MININT64, G_MAXINT64, 0,
                                                         G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
    g_object_class_install_property (gobject_class,
                                     PROP_VERSION,
                                     g_param_spec_string ("version",
                                                          "version",
                                                          "Snap version",
                                                          NULL,
                                                          G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
}

static void
snapd_channel_init (SnapdChannel *channel)
{
}
