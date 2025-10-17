/**
 * Copyright (c) 2011-2025 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_NETWORK_PROTOCOL_WEBSOCKET_HANDSHAKE_HPP
#define LIBBITCOIN_NETWORK_PROTOCOL_WEBSOCKET_HANDSHAKE_HPP

#include <memory>
#include <bitcoin/network/channels/channels.hpp>
#include <bitcoin/network/define.hpp>
#include <bitcoin/network/protocols/protocol_http.hpp>

namespace libbitcoin {
namespace network {

class BCT_API protocol_websocket_handshake
 : public protocol_http
{
public:
    typedef std::shared_ptr<protocol_websocket_handshake> ptr;
    using channel_t = channel_http;
    using options_t = channel_t::options_t;

protected:
    protocol_websocket_handshake(const session::ptr& session,
        const channel::ptr& channel, const options_t& options) NOEXCEPT
      : protocol_http(session, channel, options)
    {
    }
};
} // namespace network
} // namespace libbitcoin

#endif
