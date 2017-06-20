/*
 * Copyright (C) 2016 Canonical Ltd.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#ifndef __SNAPD_LOGIN_H__
#define __SNAPD_LOGIN_H__

#if !defined(__SNAPD_GLIB_INSIDE__) && !defined(SNAPD_COMPILATION)
#error "Only <snapd-glib/snapd-glib.h> can be included directly."
#endif

#include <glib-object.h>
#include <snapd-glib/glib-compat.h>
#include <gio/gio.h>

#include <snapd-glib/snapd-auth-data.h>

G_BEGIN_DECLS

SnapdAuthData          *snapd_login_sync                           (const gchar          *username,
                                                                    const gchar          *password,
                                                                    const gchar          *otp,
                                                                    GCancellable         *cancellable,
                                                                    GError              **error);
void                    snapd_login_async                          (const gchar          *username,
                                                                    const gchar          *password,
                                                                    const gchar          *otp,
                                                                    GCancellable         *cancellable,
                                                                    GAsyncReadyCallback   callback,
                                                                    gpointer              user_data);
SnapdAuthData          *snapd_login_finish                         (GAsyncResult         *result,
                                                                    GError              **error);

G_END_DECLS

#endif /* __SNAPD_LOGIN_H__ */
