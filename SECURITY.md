# Security Policy

## Supported Versions

| Version | Supported          |
|---------|--------------------|
| 1.0.x   | :white_check_mark: |
| < 1.0   | :x:                |

## Reporting a Vulnerability

This is a hobby/educational hardware project (an Arduino firmware sketch and
a Processing visualizer), so "vulnerabilities" here mostly mean things like:
unsafe serial-data parsing that could crash the visualizer, or firmware
behavior that could damage hardware (e.g. an unbounded servo write).

If you find such an issue:

1. **Do not** open a public issue with exploit details.
2. Instead, contact the maintainer privately via a GitHub Security Advisory
   (repo → **Security** tab → **Report a vulnerability**), or email the
   address listed in the maintainer's GitHub profile.
3. Include the affected file(s), a description of the issue, and steps to
   reproduce if possible.

You can expect an initial response within **7 days**. Fixes will be
released as a patch version and noted in `CHANGELOG.md`.

## Scope

This project does not handle networking, authentication, or user data. The
main risk surfaces are:
- Malformed serial data reaching the Processing visualizer (`serialEvent`).
- Firmware timing/range bugs that could cause erratic servo or buzzer behavior.

Reports about these areas are welcome even if they aren't "security" issues
in the traditional sense.
