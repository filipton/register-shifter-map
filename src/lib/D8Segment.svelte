<script lang="ts">
    export let onChangeSegment: (i: number) => void;
    export let showDot: boolean;
    export let segments: number[];
</script>

<div style="display: flex">
    <table style="margin-top: 30px">
        <tr>
            <td></td>

            <td style="width: calc(var(--segment-size) * 3)">
                <button
                    class={segments[0] == 0 ? "" : "clicked"}
                    on:click={() => onChangeSegment(0)}
                >
                    0
                </button>
            </td>

            <td></td>
        </tr>

        <tr>
            <td style="height: calc(var(--segment-size) * 3)">
                <button
                    class={segments[1] == 0 ? "" : "clicked"}
                    on:click={() => onChangeSegment(1)}
                >
                    1
                </button>
            </td>

            <td></td>

            <td style="height: calc(var(--segment-size) * 3)">
                <button
                    class={segments[2] == 0 ? "" : "clicked"}
                    on:click={() => onChangeSegment(2)}
                >
                    2
                </button>
            </td>
        </tr>

        <tr>
            <td></td>

            <td style="width: calc(var(--segment-size) * 3)">
                <button
                    class={segments[3] == 0 ? "" : "clicked"}
                    on:click={() => onChangeSegment(3)}
                >
                    3
                </button>
            </td>

            <td></td>
        </tr>

        <tr>
            <td style="height: calc(var(--segment-size) * 3)">
                <button
                    class={segments[4] == 0 ? "" : "clicked"}
                    on:click={() => onChangeSegment(4)}
                >
                    4
                </button>
            </td>

            <td></td>

            <td style="height: calc(var(--segment-size) * 3)">
                <button
                    class={segments[5] == 0 ? "" : "clicked"}
                    on:click={() => onChangeSegment(5)}
                >
                    5
                </button>
            </td>
        </tr>

        <tr>
            <td></td>

            <td style="width: calc(var(--segment-size) * 3)">
                <button
                    class={segments[6] == 0 ? "" : "clicked"}
                    on:click={() => onChangeSegment(6)}
                >
                    6
                </button>
            </td>

            <td></td>
        </tr>
    </table>

    {#if showDot}
        <div class="dot">
            <button
                class={segments[7] == 0 ? "" : "clicked"}
                on:click={() => onChangeSegment(7)}
            >
                7
            </button>
        </div>
    {/if}
</div>

<style>
    :root {
        --segment-size: 50px;
    }

    .dot {
        width: var(--segment-size);
        height: var(--segment-size);
        border-radius: 50%;
        border: 1px solid gray;
        overflow: hidden;
        align-self: self-end;
        margin-left: var(--segment-size);
    }

    button {
        width: 100%;
        height: 100%;
        border: none;
        cursor: pointer;
    }

    .clicked {
        background-color: red;
    }

    table,
    tr,
    td {
        border-collapse: collapse;
        border: 1px solid gray;
    }

    td {
        width: var(--segment-size);
        height: var(--segment-size);
    }
</style>
