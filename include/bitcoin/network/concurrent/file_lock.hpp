/**
 * Copyright (c) 2011-2021 libbitcoin developers (see AUTHORS)
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
#ifndef LIBBITCOIN_NETWORK_CONCURRENT_FILE_LOCK_HPP
#define LIBBITCOIN_NETWORK_CONCURRENT_FILE_LOCK_HPP

#include <string>
#include <boost/filesystem.hpp>
#include <bitcoin/system.hpp>
#include <bitcoin/network/define.hpp>

namespace libbitcoin {
namespace network {

/// This class is not thread safe, and does not throw.
class BCT_API file_lock
{
public:
    file_lock(const boost::filesystem::path& file) noexcept;

    std::string file() const noexcept;

    /// True if file exists.
    bool exists() const noexcept;

    /// True if file exists or was created.
    bool create() noexcept;

    /// True if file does not exist or was deleted.
    bool destroy() noexcept;

private:
    const boost::filesystem::path file_;
};

} // namespace network
} // namespace libbitcoin

#endif
