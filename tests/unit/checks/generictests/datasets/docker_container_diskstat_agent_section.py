# -*- encoding: utf-8
# yapf: disable


checkname = 'docker_container_diskstat'


info = [[None, '[time]'],
        [None, '1527265297'],
        [None, '[io_service_bytes]'],
        [None, '8:0', 'Read', '229888'],
        [None, '8:0', 'Write', '0'],
        [None, '8:0', 'Sync', '0'],
        [None, '8:0', 'Async', '229888'],
        [None, '8:0', 'Total', '229888'],
        [None, '253:11', 'Read', '229888'],
        [None, '253:11', 'Write', '0'],
        [None, '253:11', 'Sync', '0'],
        [None, '253:11', 'Async', '229888'],
        [None, '253:11', 'Total', '229888'],
        [None, '253:12', 'Read', '229888'],
        [None, '253:12', 'Write', '0'],
        [None, '253:12', 'Sync', '0'],
        [None, '253:12', 'Async', '229888'],
        [None, '253:12', 'Total', '229888'],
        [None, '253:13', 'Read', '47256064'],
        [None, '253:13', 'Write', '0'],
        [None, '253:13', 'Sync', '0'],
        [None, '253:13', 'Async', '47256064'],
        [None, '253:13', 'Total', '47256064'],
        [None, 'Total', '47945728'],
        [None, '[io_serviced]'],
        [None, '8:0', 'Read', '18'],
        [None, '8:0', 'Write', '0'],
        [None, '8:0', 'Sync', '0'],
        [None, '8:0', 'Async', '18'],
        [None, '8:0', 'Total', '18'],
        [None, '253:11', 'Read', '18'],
        [None, '253:11', 'Write', '0'],
        [None, '253:11', 'Sync', '0'],
        [None, '253:11', 'Async', '18'],
        [None, '253:11', 'Total', '18'],
        [None, '253:12', 'Read', '18'],
        [None, '253:12', 'Write', '0'],
        [None, '253:12', 'Sync', '0'],
        [None, '253:12', 'Async', '18'],
        [None, '253:12', 'Total', '18'],
        [None, '253:13', 'Read', '1584'],
        [None, '253:13', 'Write', '0'],
        [None, '253:13', 'Sync', '0'],
        [None, '253:13', 'Async', '1584'],
        [None, '253:13', 'Total', '1584'],
        [None, 'Total', '1638'],
        [None, '[names]'],
        [None, 'dm-0', '253:0'],
        [None, 'dm-1', '253:1'],
        [None, 'dm-10', '253:10'],
        [None, 'dm-11', '253:11'],
        [None, 'dm-12', '253:12'],
        [None, 'dm-13', '253:13'],
        [None, 'dm-14', '253:14'],
        [None, 'dm-15', '253:15'],
        [None, 'dm-16', '253:16'],
        [None, 'dm-17', '253:17'],
        [None, 'dm-18', '253:18'],
        [None, 'dm-19', '253:19'],
        [None, 'dm-2', '253:2'],
        [None, 'dm-20', '253:20'],
        [None, 'dm-21', '253:21'],
        [None, 'dm-22', '253:22'],
        [None, 'dm-23', '253:23'],
        [None, 'dm-24', '253:24'],
        [None, 'dm-3', '253:3'],
        [None, 'dm-4', '253:4'],
        [None, 'dm-5', '253:5'],
        [None, 'dm-6', '253:6'],
        [None, 'dm-7', '253:7'],
        [None, 'dm-8', '253:8'],
        [None, 'dm-9', '253:9'],
        [None, 'sda', '8:0']]


discovery = {'': [('SUMMARY', 'diskstat_default_levels')]}


checks = {'': [('SUMMARY',
                {},
                [(0,
                  'Read: 0.00 B/s',
                  [('disk_read_throughput', 0.0, None, None, None, None)]),
                 (0,
                  'Write: 0.00 B/s',
                  [('disk_write_throughput', 0.0, None, None, None, None)]),
                 (0,
                  'Read operations: 0.00 1/s',
                  [('disk_read_ios', 0.0, None, None, None, None)]),
                 (0,
                  'Write operations: 0.00 1/s',
                  [('disk_write_ios', 0.0, None, None, None, None)])])]}