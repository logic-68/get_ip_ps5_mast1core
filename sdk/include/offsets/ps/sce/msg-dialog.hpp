#pragma once

// sceMsgDialog.sprx

#define SCE_MSG_DIALOG_GET_STATUS_OFFSET_UPDATE                0x80
#define SCE_MSG_DIALOG_PROGRESS_BAR_INC_OFFSET_TERMINATE       0x70
#define SCE_MSG_DIALOG_PROGRESS_BAR_SET_VALUE_OFFSET_TERMINATE 0x140
#define SCE_MSG_DIALOG_PROGRESS_BAR_SET_MSG_OFFSET_TERMINATE   0x200

#if ((defined(PS4) && PS4 && defined(FIRMWARE) && FIRMWARE >= 1001) || (defined(PS5) && PS5 && defined(FIRMWARE) && FIRMWARE >= 650))
    #define SCE_MSG_DIALOG_CLOSE_OFFSET_GET_RESULT                 0x280
#else
    #define SCE_MSG_DIALOG_CLOSE_OFFSET_GET_RESULT                 0x270
#endif