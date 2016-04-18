/*
 * Asterisk -- An open source telephony toolkit.
 *
 * Copyright (C) 2012 - 2013, Digium, Inc.
 *
 * David M. Lee, II <dlee@digium.com>
 *
 * See http://www.asterisk.org for more information about
 * the Asterisk project. Please do not directly contact
 * any of the maintainers of this project for assistance;
 * the project provides a web site, mailing lists and IRC
 * channels for your use.
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2. See the LICENSE file
 * at the top of the source tree.
 */

/*! \file
 *
 * \brief Generated file - declares stubs to be implemented in
 * res/ari/resource_channels.c
 *
 * Channel resources
 *
 * \author David M. Lee, II <dlee@digium.com>
 */

/*
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * !!!!!                               DO NOT EDIT                        !!!!!
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * This file is generated by a mustache template. Please see the original
 * template in rest-api-templates/ari_resource.h.mustache
 */

#ifndef _ASTERISK_RESOURCE_CHANNELS_H
#define _ASTERISK_RESOURCE_CHANNELS_H

#include "asterisk/ari.h"

/*! Argument struct for ast_ari_channels_list() */
struct ast_ari_channels_list_args {
};
/*!
 * \brief List all active channels in Asterisk.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_list(struct ast_variable *headers, struct ast_ari_channels_list_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_originate() */
struct ast_ari_channels_originate_args {
	/*! Endpoint to call. */
	const char *endpoint;
	/*! The extension to dial after the endpoint answers. Mutually exclusive with 'app'. */
	const char *extension;
	/*! The context to dial after the endpoint answers. If omitted, uses 'default'. Mutually exclusive with 'app'. */
	const char *context;
	/*! The priority to dial after the endpoint answers. If omitted, uses 1. Mutually exclusive with 'app'. */
	long priority;
	/*! The label to dial after the endpoint answers. Will supersede 'priority' if provided. Mutually exclusive with 'app'. */
	const char *label;
	/*! The application that is subscribed to the originated channel. When the channel is answered, it will be passed to this Stasis application. Mutually exclusive with 'context', 'extension', 'priority', and 'label'. */
	const char *app;
	/*! The application arguments to pass to the Stasis application provided by 'app'. Mutually exclusive with 'context', 'extension', 'priority', and 'label'. */
	const char *app_args;
	/*! CallerID to use when dialing the endpoint or extension. */
	const char *caller_id;
	/*! Timeout (in seconds) before giving up dialing, or -1 for no timeout. */
	int timeout;
	/*! The "variables" key in the body object holds variable key/value pairs to set on the channel on creation. Other keys in the body object are interpreted as query parameters. Ex. { "endpoint": "SIP/Alice", "variables": { "CALLERID(name)": "Alice" } } */
	struct ast_json *variables;
	/*! The unique id to assign the channel on creation. */
	const char *channel_id;
	/*! The unique id to assign the second channel when using local channels. */
	const char *other_channel_id;
	/*! The unique id of the channel which is originating this one. */
	const char *originator;
};
/*!
 * \brief Body parsing function for /channels.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_originate_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_originate_args *args);

/*!
 * \brief Create a new channel (originate).
 *
 * The new channel is created immediately and a snapshot of it returned. If a Stasis application is provided it will be automatically subscribed to the originated channel for further events and updates.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_originate(struct ast_variable *headers, struct ast_ari_channels_originate_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_create() */
struct ast_ari_channels_create_args {
	/*! Endpoint for channel communication */
	const char *endpoint;
	/*! Stasis Application to place channel into */
	const char *app;
	/*! The application arguments to pass to the Stasis application provided by 'app'. Mutually exclusive with 'context', 'extension', 'priority', and 'label'. */
	const char *app_args;
	/*! The unique id to assign the channel on creation. */
	const char *channel_id;
	/*! The unique id to assign the second channel when using local channels. */
	const char *other_channel_id;
	/*! Unique ID of the calling channel */
	const char *originator;
};
/*!
 * \brief Body parsing function for /channels/create.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_create_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_create_args *args);

/*!
 * \brief Create channel.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_create(struct ast_variable *headers, struct ast_ari_channels_create_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_get() */
struct ast_ari_channels_get_args {
	/*! Channel's id */
	const char *channel_id;
};
/*!
 * \brief Channel details.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_get(struct ast_variable *headers, struct ast_ari_channels_get_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_originate_with_id() */
struct ast_ari_channels_originate_with_id_args {
	/*! The unique id to assign the channel on creation. */
	const char *channel_id;
	/*! Endpoint to call. */
	const char *endpoint;
	/*! The extension to dial after the endpoint answers. Mutually exclusive with 'app'. */
	const char *extension;
	/*! The context to dial after the endpoint answers. If omitted, uses 'default'. Mutually exclusive with 'app'. */
	const char *context;
	/*! The priority to dial after the endpoint answers. If omitted, uses 1. Mutually exclusive with 'app'. */
	long priority;
	/*! The label to dial after the endpoint answers. Will supersede 'priority' if provided. Mutually exclusive with 'app'. */
	const char *label;
	/*! The application that is subscribed to the originated channel. When the channel is answered, it will be passed to this Stasis application. Mutually exclusive with 'context', 'extension', 'priority', and 'label'. */
	const char *app;
	/*! The application arguments to pass to the Stasis application provided by 'app'. Mutually exclusive with 'context', 'extension', 'priority', and 'label'. */
	const char *app_args;
	/*! CallerID to use when dialing the endpoint or extension. */
	const char *caller_id;
	/*! Timeout (in seconds) before giving up dialing, or -1 for no timeout. */
	int timeout;
	/*! The "variables" key in the body object holds variable key/value pairs to set on the channel on creation. Other keys in the body object are interpreted as query parameters. Ex. { "endpoint": "SIP/Alice", "variables": { "CALLERID(name)": "Alice" } } */
	struct ast_json *variables;
	/*! The unique id to assign the second channel when using local channels. */
	const char *other_channel_id;
	/*! The unique id of the channel which is originating this one. */
	const char *originator;
};
/*!
 * \brief Body parsing function for /channels/{channelId}.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_originate_with_id_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_originate_with_id_args *args);

/*!
 * \brief Create a new channel (originate with id).
 *
 * The new channel is created immediately and a snapshot of it returned. If a Stasis application is provided it will be automatically subscribed to the originated channel for further events and updates.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_originate_with_id(struct ast_variable *headers, struct ast_ari_channels_originate_with_id_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_hangup() */
struct ast_ari_channels_hangup_args {
	/*! Channel's id */
	const char *channel_id;
	/*! Reason for hanging up the channel */
	const char *reason;
};
/*!
 * \brief Body parsing function for /channels/{channelId}.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_hangup_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_hangup_args *args);

/*!
 * \brief Delete (i.e. hangup) a channel.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_hangup(struct ast_variable *headers, struct ast_ari_channels_hangup_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_continue_in_dialplan() */
struct ast_ari_channels_continue_in_dialplan_args {
	/*! Channel's id */
	const char *channel_id;
	/*! The context to continue to. */
	const char *context;
	/*! The extension to continue to. */
	const char *extension;
	/*! The priority to continue to. */
	int priority;
	/*! The label to continue to - will supersede 'priority' if both are provided. */
	const char *label;
};
/*!
 * \brief Body parsing function for /channels/{channelId}/continue.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_continue_in_dialplan_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_continue_in_dialplan_args *args);

/*!
 * \brief Exit application; continue execution in the dialplan.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_continue_in_dialplan(struct ast_variable *headers, struct ast_ari_channels_continue_in_dialplan_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_redirect() */
struct ast_ari_channels_redirect_args {
	/*! Channel's id */
	const char *channel_id;
	/*! The endpoint to redirect the channel to */
	const char *endpoint;
};
/*!
 * \brief Body parsing function for /channels/{channelId}/redirect.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_redirect_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_redirect_args *args);

/*!
 * \brief Redirect the channel to a different location.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_redirect(struct ast_variable *headers, struct ast_ari_channels_redirect_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_answer() */
struct ast_ari_channels_answer_args {
	/*! Channel's id */
	const char *channel_id;
};
/*!
 * \brief Answer a channel.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_answer(struct ast_variable *headers, struct ast_ari_channels_answer_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_ring() */
struct ast_ari_channels_ring_args {
	/*! Channel's id */
	const char *channel_id;
};
/*!
 * \brief Indicate ringing to a channel.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_ring(struct ast_variable *headers, struct ast_ari_channels_ring_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_ring_stop() */
struct ast_ari_channels_ring_stop_args {
	/*! Channel's id */
	const char *channel_id;
};
/*!
 * \brief Stop ringing indication on a channel if locally generated.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_ring_stop(struct ast_variable *headers, struct ast_ari_channels_ring_stop_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_send_dtmf() */
struct ast_ari_channels_send_dtmf_args {
	/*! Channel's id */
	const char *channel_id;
	/*! DTMF To send. */
	const char *dtmf;
	/*! Amount of time to wait before DTMF digits (specified in milliseconds) start. */
	int before;
	/*! Amount of time in between DTMF digits (specified in milliseconds). */
	int between;
	/*! Length of each DTMF digit (specified in milliseconds). */
	int duration;
	/*! Amount of time to wait after DTMF digits (specified in milliseconds) end. */
	int after;
};
/*!
 * \brief Body parsing function for /channels/{channelId}/dtmf.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_send_dtmf_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_send_dtmf_args *args);

/*!
 * \brief Send provided DTMF to a given channel.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_send_dtmf(struct ast_variable *headers, struct ast_ari_channels_send_dtmf_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_mute() */
struct ast_ari_channels_mute_args {
	/*! Channel's id */
	const char *channel_id;
	/*! Direction in which to mute audio */
	const char *direction;
};
/*!
 * \brief Body parsing function for /channels/{channelId}/mute.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_mute_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_mute_args *args);

/*!
 * \brief Mute a channel.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_mute(struct ast_variable *headers, struct ast_ari_channels_mute_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_unmute() */
struct ast_ari_channels_unmute_args {
	/*! Channel's id */
	const char *channel_id;
	/*! Direction in which to unmute audio */
	const char *direction;
};
/*!
 * \brief Body parsing function for /channels/{channelId}/mute.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_unmute_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_unmute_args *args);

/*!
 * \brief Unmute a channel.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_unmute(struct ast_variable *headers, struct ast_ari_channels_unmute_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_hold() */
struct ast_ari_channels_hold_args {
	/*! Channel's id */
	const char *channel_id;
};
/*!
 * \brief Hold a channel.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_hold(struct ast_variable *headers, struct ast_ari_channels_hold_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_unhold() */
struct ast_ari_channels_unhold_args {
	/*! Channel's id */
	const char *channel_id;
};
/*!
 * \brief Remove a channel from hold.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_unhold(struct ast_variable *headers, struct ast_ari_channels_unhold_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_start_moh() */
struct ast_ari_channels_start_moh_args {
	/*! Channel's id */
	const char *channel_id;
	/*! Music on hold class to use */
	const char *moh_class;
};
/*!
 * \brief Body parsing function for /channels/{channelId}/moh.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_start_moh_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_start_moh_args *args);

/*!
 * \brief Play music on hold to a channel.
 *
 * Using media operations such as /play on a channel playing MOH in this manner will suspend MOH without resuming automatically. If continuing music on hold is desired, the stasis application must reinitiate music on hold.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_start_moh(struct ast_variable *headers, struct ast_ari_channels_start_moh_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_stop_moh() */
struct ast_ari_channels_stop_moh_args {
	/*! Channel's id */
	const char *channel_id;
};
/*!
 * \brief Stop playing music on hold to a channel.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_stop_moh(struct ast_variable *headers, struct ast_ari_channels_stop_moh_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_start_silence() */
struct ast_ari_channels_start_silence_args {
	/*! Channel's id */
	const char *channel_id;
};
/*!
 * \brief Play silence to a channel.
 *
 * Using media operations such as /play on a channel playing silence in this manner will suspend silence without resuming automatically.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_start_silence(struct ast_variable *headers, struct ast_ari_channels_start_silence_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_stop_silence() */
struct ast_ari_channels_stop_silence_args {
	/*! Channel's id */
	const char *channel_id;
};
/*!
 * \brief Stop playing silence to a channel.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_stop_silence(struct ast_variable *headers, struct ast_ari_channels_stop_silence_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_play() */
struct ast_ari_channels_play_args {
	/*! Channel's id */
	const char *channel_id;
	/*! Array of Media URIs to play. */
	const char **media;
	/*! Length of media array. */
	size_t media_count;
	/*! Parsing context for media. */
	char *media_parse;
	/*! For sounds, selects language for sound. */
	const char *lang;
	/*! Number of milliseconds to skip before playing. Only applies to the first URI if multiple media URIs are specified. */
	int offsetms;
	/*! Number of milliseconds to skip for forward/reverse operations. */
	int skipms;
	/*! Playback ID. */
	const char *playback_id;
};
/*!
 * \brief Body parsing function for /channels/{channelId}/play.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_play_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_play_args *args);

/*!
 * \brief Start playback of media.
 *
 * The media URI may be any of a number of URI's. Currently sound:, recording:, number:, digits:, characters:, and tone: URI's are supported. This operation creates a playback resource that can be used to control the playback of media (pause, rewind, fast forward, etc.)
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_play(struct ast_variable *headers, struct ast_ari_channels_play_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_play_with_id() */
struct ast_ari_channels_play_with_id_args {
	/*! Channel's id */
	const char *channel_id;
	/*! Playback ID. */
	const char *playback_id;
	/*! Array of Media URIs to play. */
	const char **media;
	/*! Length of media array. */
	size_t media_count;
	/*! Parsing context for media. */
	char *media_parse;
	/*! For sounds, selects language for sound. */
	const char *lang;
	/*! Number of milliseconds to skip before playing. Only applies to the first URI if multiple media URIs are specified. */
	int offsetms;
	/*! Number of milliseconds to skip for forward/reverse operations. */
	int skipms;
};
/*!
 * \brief Body parsing function for /channels/{channelId}/play/{playbackId}.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_play_with_id_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_play_with_id_args *args);

/*!
 * \brief Start playback of media and specify the playbackId.
 *
 * The media URI may be any of a number of URI's. Currently sound:, recording:, number:, digits:, characters:, and tone: URI's are supported. This operation creates a playback resource that can be used to control the playback of media (pause, rewind, fast forward, etc.)
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_play_with_id(struct ast_variable *headers, struct ast_ari_channels_play_with_id_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_record() */
struct ast_ari_channels_record_args {
	/*! Channel's id */
	const char *channel_id;
	/*! Recording's filename */
	const char *name;
	/*! Format to encode audio in */
	const char *format;
	/*! Maximum duration of the recording, in seconds. 0 for no limit */
	int max_duration_seconds;
	/*! Maximum duration of silence, in seconds. 0 for no limit */
	int max_silence_seconds;
	/*! Action to take if a recording with the same name already exists. */
	const char *if_exists;
	/*! Play beep when recording begins */
	int beep;
	/*! DTMF input to terminate recording */
	const char *terminate_on;
};
/*!
 * \brief Body parsing function for /channels/{channelId}/record.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_record_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_record_args *args);

/*!
 * \brief Start a recording.
 *
 * Record audio from a channel. Note that this will not capture audio sent to the channel. The bridge itself has a record feature if that's what you want.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_record(struct ast_variable *headers, struct ast_ari_channels_record_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_get_channel_var() */
struct ast_ari_channels_get_channel_var_args {
	/*! Channel's id */
	const char *channel_id;
	/*! The channel variable or function to get */
	const char *variable;
};
/*!
 * \brief Body parsing function for /channels/{channelId}/variable.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_get_channel_var_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_get_channel_var_args *args);

/*!
 * \brief Get the value of a channel variable or function.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_get_channel_var(struct ast_variable *headers, struct ast_ari_channels_get_channel_var_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_set_channel_var() */
struct ast_ari_channels_set_channel_var_args {
	/*! Channel's id */
	const char *channel_id;
	/*! The channel variable or function to set */
	const char *variable;
	/*! The value to set the variable to */
	const char *value;
};
/*!
 * \brief Body parsing function for /channels/{channelId}/variable.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_set_channel_var_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_set_channel_var_args *args);

/*!
 * \brief Set the value of a channel variable or function.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_set_channel_var(struct ast_variable *headers, struct ast_ari_channels_set_channel_var_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_snoop_channel() */
struct ast_ari_channels_snoop_channel_args {
	/*! Channel's id */
	const char *channel_id;
	/*! Direction of audio to spy on */
	const char *spy;
	/*! Direction of audio to whisper into */
	const char *whisper;
	/*! Application the snooping channel is placed into */
	const char *app;
	/*! The application arguments to pass to the Stasis application */
	const char *app_args;
	/*! Unique ID to assign to snooping channel */
	const char *snoop_id;
};
/*!
 * \brief Body parsing function for /channels/{channelId}/snoop.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_snoop_channel_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_snoop_channel_args *args);

/*!
 * \brief Start snooping.
 *
 * Snoop (spy/whisper) on a specific channel.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_snoop_channel(struct ast_variable *headers, struct ast_ari_channels_snoop_channel_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_snoop_channel_with_id() */
struct ast_ari_channels_snoop_channel_with_id_args {
	/*! Channel's id */
	const char *channel_id;
	/*! Unique ID to assign to snooping channel */
	const char *snoop_id;
	/*! Direction of audio to spy on */
	const char *spy;
	/*! Direction of audio to whisper into */
	const char *whisper;
	/*! Application the snooping channel is placed into */
	const char *app;
	/*! The application arguments to pass to the Stasis application */
	const char *app_args;
};
/*!
 * \brief Body parsing function for /channels/{channelId}/snoop/{snoopId}.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_snoop_channel_with_id_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_snoop_channel_with_id_args *args);

/*!
 * \brief Start snooping.
 *
 * Snoop (spy/whisper) on a specific channel.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_snoop_channel_with_id(struct ast_variable *headers, struct ast_ari_channels_snoop_channel_with_id_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_channels_dial() */
struct ast_ari_channels_dial_args {
	/*! Channel's id */
	const char *channel_id;
	/*! Channel ID of caller */
	const char *caller;
	/*! Dial timeout */
	int timeout;
};
/*!
 * \brief Body parsing function for /channels/{channelId}/dial.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_channels_dial_parse_body(
	struct ast_json *body,
	struct ast_ari_channels_dial_args *args);

/*!
 * \brief Dial a created channel.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_channels_dial(struct ast_variable *headers, struct ast_ari_channels_dial_args *args, struct ast_ari_response *response);

#endif /* _ASTERISK_RESOURCE_CHANNELS_H */
