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
#ifndef LIBBITCOIN_NETWORK_SESSION_INBOUND_CLIENT_HPP
#define LIBBITCOIN_NETWORK_SESSION_INBOUND_CLIENT_HPP

#include <memory>
#include <bitcoin/system.hpp>
#include <bitcoin/network/define.hpp>
#include <bitcoin/network/log/log.hpp>
#include <bitcoin/network/net/net.hpp>
#include <bitcoin/network/sessions/session_client.hpp>
#include <bitcoin/network/settings.hpp>

namespace libbitcoin {
namespace network {

class net;

/// Inbound client connections session, thread safe.
class BCT_API session_inbound_client
  : public session_client, protected tracker<session_inbound_client>
{
public:
    typedef std::shared_ptr<session_inbound_client> ptr;

    /// Construct an instance (network should be started).
    session_inbound_client(net& network, uint64_t identifier) NOEXCEPT;

    /// Start accepting inbound connections as configured (call from network strand).
    void start(result_handler&& handler) NOEXCEPT override;

protected:
    /// Overridden to change version protocol (base calls from channel strand).
    void attach_handshake(const channel::ptr& channel,
        result_handler&& handler) NOEXCEPT override;

    /// Overridden to change channel protocols (base calls from channel strand).
    void attach_protocols(const channel::ptr& channel) NOEXCEPT override;

    /// Start accepting based on configuration (called from start).
    virtual void start_accept(const code& ec,
        const acceptor::ptr& acceptor) NOEXCEPT;

    /// Inbound services are enabled (e.g. because node is current).
    virtual bool enabled() const NOEXCEPT;

private:
    void handle_started(const code& ec, const result_handler& handler) NOEXCEPT;
    void handle_accept(const code& ec, const socket::ptr& socket,
        const acceptor::ptr& acceptor) NOEXCEPT;

    void handle_channel_start(const code& ec,
        const channel::ptr& channel) NOEXCEPT;
    void handle_channel_stop(const code& ec,
        const channel::ptr& channel) NOEXCEPT;
};

} // namespace network
} // namespace libbitcoin

#endif
