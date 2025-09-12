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
#ifndef LIBBITCOIN_NETWORK_SETTINGS_HPP
#define LIBBITCOIN_NETWORK_SETTINGS_HPP

#include <filesystem>
#include <bitcoin/system.hpp>
#include <bitcoin/network/async/async.hpp>
#include <bitcoin/network/client.hpp>
#include <bitcoin/network/config/config.hpp>
#include <bitcoin/network/define.hpp>
#include <bitcoin/network/messages/p2p/messages.hpp>

namespace libbitcoin {
namespace network {

/// Common network configuration settings, properties not thread safe.
struct BCT_API settings
{
    DEFAULT_COPY_MOVE_DESTRUCT(settings);

    settings() NOEXCEPT;
    settings(system::chain::selection context) NOEXCEPT;

    /// Properties.
    uint32_t threads;
    uint16_t address_upper;
    uint16_t address_lower;
    uint32_t protocol_maximum;
    uint32_t protocol_minimum;
    uint64_t services_maximum;
    uint64_t services_minimum;
    uint64_t invalid_services;
    bool enable_address;
    bool enable_address_v2;
    bool enable_witness_tx;
    bool enable_compact;
    bool enable_alert;
    bool enable_reject;
    bool enable_relay;
    bool enable_ipv6;
    bool enable_loopback;
    bool validate_checksum;
    uint32_t identifier;
    uint16_t inbound_connections;
    uint16_t outbound_connections;
    uint16_t connect_batch_size;
    uint32_t retry_timeout_seconds;
    uint32_t connect_timeout_seconds;
    uint32_t handshake_timeout_seconds;
    uint32_t seeding_timeout_seconds;
    uint32_t channel_heartbeat_minutes;
    uint32_t channel_inactivity_minutes;
    uint32_t channel_expiration_minutes;
    uint32_t maximum_skew_minutes;
    uint32_t host_pool_capacity;
    uint32_t minimum_buffer;
    uint32_t rate_limit;
    std::string user_agent;
    std::filesystem::path path{};
    config::endpoints peers{};
    config::endpoints seeds{};
    config::authorities selfs{};
    config::authorities binds{};
    config::authorities blacklists{};
    config::authorities whitelists{};
    config::authorities friends{};

    /// Client settings.
    network::client client{};

    /// Set friends.
    virtual void initialize() NOEXCEPT;

    /// Helpers.
    virtual bool witness_node() const NOEXCEPT;
    virtual bool inbound_enabled() const NOEXCEPT;
    virtual bool outbound_enabled() const NOEXCEPT;
    virtual bool advertise_enabled() const NOEXCEPT;
    virtual size_t maximum_payload() const NOEXCEPT;
    virtual config::authority first_self() const NOEXCEPT;
    virtual steady_clock::duration retry_timeout() const NOEXCEPT;
    virtual steady_clock::duration connect_timeout() const NOEXCEPT;
    virtual steady_clock::duration channel_handshake() const NOEXCEPT;
    virtual steady_clock::duration channel_germination() const NOEXCEPT;
    virtual steady_clock::duration channel_heartbeat() const NOEXCEPT;
    virtual steady_clock::duration channel_inactivity() const NOEXCEPT;
    virtual steady_clock::duration channel_expiration() const NOEXCEPT;
    virtual steady_clock::duration maximum_skew() const NOEXCEPT;
    virtual size_t minimum_address_count() const NOEXCEPT;
    virtual std::filesystem::path file() const NOEXCEPT;

    /// Filters.
    virtual bool disabled(const messages::p2p::address_item& item) const NOEXCEPT;
    virtual bool insufficient(const messages::p2p::address_item& item) const NOEXCEPT;
    virtual bool unsupported(const messages::p2p::address_item& item) const NOEXCEPT;
    virtual bool blacklisted(const messages::p2p::address_item& item) const NOEXCEPT;
    virtual bool whitelisted(const messages::p2p::address_item& item) const NOEXCEPT;
    virtual bool peered(const messages::p2p::address_item& item) const NOEXCEPT;
    virtual bool excluded(const messages::p2p::address_item& item) const NOEXCEPT;
};

} // namespace network
} // namespace libbitcoin

#endif
